// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "RequestHandler.hpp"

#include <QTextStream>
#include <iostream>

void RequestHandler::accepted(HttpHeader header, HttpData data)
{
  data->open(QIODevice::ReadWrite);
  QTextStream text{data.data()};

  std::cout << "---- header ----" << std::endl;

  for (auto itr = header.constBegin(); itr != header.constEnd(); itr++) {
    std::cout << itr.key().toStdString() << ": " << itr.value().toStdString() << std::endl;
  }

  std::cout << "---- content ----" << std::endl;
  std::cout << text.readAll().toStdString() << std::endl;

  text << "Content-type: text/html" << HttpHeaderSeparator;
  text << "hello " << count;

  count++;
}
