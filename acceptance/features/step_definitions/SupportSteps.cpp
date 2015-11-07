// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "Context.hpp"

#include <cucumber-cpp/defs.hpp>

namespace
{

  BEFORE()
  {
    cucumber::ScenarioScope<Context> context;

    context->data->close();
    context->xmlData.clear();
  }

}
