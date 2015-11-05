#include <MumeWeb.hpp>
#include <IMumeDbus.hpp>

#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

#include <string>
#include <QBuffer>
#include <QDomDocument>

namespace
{

using cucumber::ScenarioScope;

class DbusDummy :
    public IMumeDbus
{
  public:
    bool switchOn;
    bool switchState() const
    {
      return switchOn;
    }
};

class MumeWeb_Context
{
  public:
    DbusDummy dbus;
    MumeWeb mumeWeb{dbus};

    QByteArray  xmlData;
    QBuffer     writer{&xmlData};
};

static bool parseOn(const std::string &value)
{
  return value == "on";
}

BEFORE()
{
  ScenarioScope<MumeWeb_Context> context;

  context->writer.close();
  context->xmlData.clear();
  ASSERT_TRUE(context->writer.open(QIODevice::WriteOnly));
}

GIVEN("^the switch is (on|off)$")
{
  REGEX_PARAM(std::string, onText);

  ScenarioScope<MumeWeb_Context> context;
  context->dbus.switchOn = parseOn(onText);
}

WHEN("^I request data$")
{
  ScenarioScope<MumeWeb_Context> context;

  context->mumeWeb.request(context->writer);
}

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

THEN("^I expect an xml with a node switch with an attribute state=\"(on|off)\"$")
{
  REGEX_PARAM(std::string, onText);
  const QString nodeName{"switch"};
  const QString attrName{"state"};

  QDomDocument domDocument;
  ScenarioScope<MumeWeb_Context> context;
  context->writer.close();
  ASSERT_TRUE(domDocument.setContent(context->xmlData));
  ASSERT_TRUE(hasElement(domDocument.documentElement(), nodeName, attrName, QString::fromStdString(onText)));
}

}
