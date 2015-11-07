// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "RequestHandler.hpp"

#include <QTextStream>

void RequestHandler::accepted(HttpHeader header, HttpData data)
{
  data->open(QIODevice::ReadWrite);
  QTextStream text{data.data()};

  text << "Content-type: text/html" << HttpHeaderSeparator;
  text << "hello " << count;

  count++;
}
