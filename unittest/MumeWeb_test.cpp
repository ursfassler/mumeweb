#include <MumeWeb.hpp>

#include "mocks/MumeDbus_Mock.hpp"

#include <gtest/gtest.h>

#include <QBuffer>
#include <QDomDocument>

namespace
{

static bool hasElement(QDomElement root, QString node, QString attr, QString value)
{
  for (auto itr = root.firstChild(); !itr.isNull(); itr = itr.nextSibling()) {
    if (itr.nodeName() == node) {
      auto element = itr.toElement();
      if (element.isNull()) {
        continue;
      }

      const auto attribute = element.attributeNode(attr);
      if (attribute.isNull()) {
        continue;
      }

      if (attribute.value() == value) {
        return true;
      }
    }
  }

  return false;
}

class MumeWeb_Test : public ::testing::Test
{
  public:
    void SetUp()
    {
      buffer.open(QBuffer::WriteOnly);
    }

    void TearDown()
    {
      buffer.close();
      storage.clear();
    }

    ::testing::NiceMock<MumeDbusMock> mumeDbus;
    MumeWeb testee{mumeDbus};
    QByteArray storage;
    QBuffer buffer{&storage};
};


TEST_F(MumeWeb_Test, request_writes_switch_state_to_response_for_on)
{
  ON_CALL(mumeDbus, switchState()).WillByDefault(::testing::Return(true));

  testee.request(buffer);

  buffer.close();
  QDomDocument doc;
  ASSERT_TRUE(doc.setContent(storage));
  ASSERT_TRUE(hasElement(doc.documentElement(), "switch", "state", "on"));
}

TEST_F(MumeWeb_Test, request_writes_switch_state_to_response_for_off)
{
  ON_CALL(mumeDbus, switchState()).WillByDefault(::testing::Return(false));

  testee.request(buffer);

  buffer.close();
  QDomDocument doc;
  ASSERT_TRUE(doc.setContent(storage));
  ASSERT_TRUE(hasElement(doc.documentElement(), "switch", "state", "off"));
}

}

