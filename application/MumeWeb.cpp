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

void MumeWeb::writeDouble(QDomElement element, std::function<void(IMumeDbus&, double)> writer)
{
  const auto valueAttr = element.attributeNode("value");
  if (!valueAttr.isNull()) {
    bool ok = false;
    double value = valueAttr.value().toDouble(&ok);
    if (ok) {
      writer(dbus, value);
    }
  }
}

void MumeWeb::parseRequest(const QDomElement request)
{
  for (auto node = request.firstChildElement(); !node.isNull(); node = node.nextSiblingElement()) {
    if (node.nodeName() == "openPositionMs") {
      writeDouble(node, &IMumeDbus::setOpenPositionMs);
    }
    if (node.nodeName() == "closePositionMs") {
      writeDouble(node, &IMumeDbus::setClosePositionMs);
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
  stream << "<switch ";
  stream << "state=\"" << (dbus.switchState() ? "on" : "off") << "\" ";
  stream << "count=\"" << dbus.count() << "\"";
  stream << "/>";
  stream << "</mume>";

  data->close();
}
