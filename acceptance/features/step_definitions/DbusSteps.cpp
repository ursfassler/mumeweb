// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "Context.hpp"

#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

namespace
{

  THEN("^I expect a D-Bus request setOpenPosition with the value ((\\d+)(\\.(\\d+))?)$")
  {
    cucumber::ScenarioScope<Context> context;

    REGEX_PARAM(double, value);

    ASSERT_DOUBLE_EQ(value, context->dbus.openPosition);
  }

}
