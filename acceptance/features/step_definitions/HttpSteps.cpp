// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "Context.hpp"

#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

namespace
{

  WHEN("^I request data$")
  {
    cucumber::ScenarioScope<Context> context;

    context->mumeWeb.request(context->header, context->data);
  }

  WHEN("^I set the http request header \"Content-Type\" to \"application/xml\"$")
  {
    cucumber::ScenarioScope<Context> context;

    context->header["Content-Type"] = "application/xml";
  }

  WHEN("^I set the http request content to:$")
  {
    cucumber::ScenarioScope<Context> context;

    REGEX_PARAM(std::string, content);

    context->xmlData.append(QByteArray::fromStdString(content));
  }

  static QString normalize(QString text)
  {
    return text.replace("\r\n", "\n");
  }

  static std::string normalize(const std::string &text)
  {
    return normalize(QString::fromStdString(text)).toStdString();
  }

  THEN("^I expect the http response:$")
  {
    REGEX_PARAM(std::string, httpResponse);

    cucumber::ScenarioScope<Context> context;

    const auto expected = normalize(httpResponse);
    const auto received = normalize(context->xmlData).toStdString();

    ASSERT_EQ(expected, received);
  }

}
