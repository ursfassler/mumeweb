#include <MumeWeb.hpp>
#include <http.hpp>

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
    }

    void TearDown()
    {
      data->close();
      storage.clear();
      header.clear();
    }

    ::testing::NiceMock<MumeDbusMock> mumeDbus;
    MumeWeb testee{mumeDbus};
    QByteArray storage;
    HttpData data{new QBuffer(&storage)};
    HttpHeader header{};

    QStringList getHeader()
    {
      const QString line{storage};
      const int idx = line.indexOf(HttpHeaderSeparator);

      if (idx == -1) {
        return line.split(HttpLineEnd);
      }

      const QString header{line.left(idx)};
      return header.split(HttpLineEnd);
    }

    QString getBody()
    {
      const QString line{storage};
      const int idx = line.indexOf(HttpHeaderSeparator);
      if (idx == -1) {
        return {};
      }
      return line.right(line.size()-idx-HttpHeaderSeparator.size());
    }
};


TEST_F(MumeWeb_Test, request_closes_the_data_stream)
{
  ON_CALL(mumeDbus, switchState()).WillByDefault(::testing::Return(true));

  testee.request(header, data);

  ASSERT_FALSE(data->isOpen());
}

TEST_F(MumeWeb_Test, request_returns_a_content_type_in_http_header)
{
  ON_CALL(mumeDbus, switchState()).WillByDefault(::testing::Return(true));

  testee.request(header, data);

  const auto header = getHeader();
  ASSERT_EQ(1, header.size());
  ASSERT_EQ("Content-Type: text/xml", header[0].toStdString());
}

TEST_F(MumeWeb_Test, request_writes_switch_state_to_response_for_on)
{
  ON_CALL(mumeDbus, switchState()).WillByDefault(::testing::Return(true));

  testee.request(header, data);

  QDomDocument doc;
  ASSERT_TRUE(doc.setContent(getBody()));
  ASSERT_TRUE(hasElement(doc.documentElement(), "switch", "state", "on"));
}

TEST_F(MumeWeb_Test, request_writes_switch_state_to_response_for_off)
{
  ON_CALL(mumeDbus, switchState()).WillByDefault(::testing::Return(false));

  testee.request(header, data);

  QDomDocument doc;
  ASSERT_TRUE(doc.setContent(getBody()));
  ASSERT_TRUE(hasElement(doc.documentElement(), "switch", "state", "off"));
}

}

