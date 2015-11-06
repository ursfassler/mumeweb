#include "Context.hpp"

#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

#include <string>

namespace
{

  static bool parseOn(const std::string &value)
  {
    return value == "on";
  }

  GIVEN("^the switch is (on|off)$")
  {
    REGEX_PARAM(std::string, onText);

    cucumber::ScenarioScope<Context> context;
    context->dbus.switchOn = parseOn(onText);
  }

}
