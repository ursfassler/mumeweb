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
