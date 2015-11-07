// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef CONTEXT
#define CONTEXT

#include <MumeWeb.hpp>
#include <IMumeDbus.hpp>
#include <http.hpp>

#include <QBuffer>

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

class Context
{
  public:
    DbusDummy dbus;
    MumeWeb mumeWeb{dbus};

    HttpHeader  header;
    QByteArray  xmlData;
    HttpData    data{new QBuffer(&xmlData)};
};

#endif // CONTEXT

