// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "MumeWeb.hpp"

#include <QTextStream>

MumeWeb::MumeWeb(IMumeDbus &aDbus) :
  dbus{aDbus}
{
}

void MumeWeb::request(HttpHeader header, HttpData data)
{
  readRequest(header, data);
  writeResponse(header, data);
}

void MumeWeb::readRequest(HttpHeader, HttpData data)
{
  data->open(QIODevice::ReadOnly);

  QDomDocument doc;
  doc.setContent(data.data());

  parseRequest(doc.documentElement());

  data->close();
}

void MumeWeb::parseRequest(const QDomElement request)
{
  for (auto node = request.firstChildElement(); !node.isNull(); node = node.nextSiblingElement()) {
    if (node.nodeName() == "openPosition") {
      const auto valueAttr = node.attributeNode("value");
      if (!valueAttr.isNull()) {
        bool ok = false;
        double value = valueAttr.value().toDouble(&ok);
        if (ok) {
          dbus.setOpenPosition(value);
        }
      }
    }
  }
}

void MumeWeb::writeResponse(HttpHeader, HttpData data)
{
  data->open(QIODevice::WriteOnly);
  QTextStream stream{data.data()};

  stream << "Content-Type: application/xml" << HttpLineEnd;

  stream << HttpLineEnd;

  stream << "<mume>";
  stream << "<switch state=\"";
  stream << (dbus.switchState() ? "on" : "off");
  stream << "\"/>";
  stream << "</mume>";

  data->close();
}
