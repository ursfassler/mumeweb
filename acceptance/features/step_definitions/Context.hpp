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
    bool switchOn{false};
    bool switchState() const override
    {
      return switchOn;
    }

    uint32_t countValue{0};
    uint32_t count() const override
    {
      return countValue;
    }

    double openPositionMs{0};
    void setOpenPositionMs(double value) override
    {
      openPositionMs = value;
    }

    double closePositionMs{0};
    void setClosePositionMs(double value) override
    {
      closePositionMs = value;
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

