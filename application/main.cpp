// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "generated/MumeSrvProxy.h"
#include "IMumeDbus.hpp"
#include "fcgi/FcgiRequest.hpp"

#include "MumeWeb.hpp"

#include <QCoreApplication>

#include <iostream>

class MumeDbus final :
    public IMumeDbus
{
  public:
    MumeDbus(QObject *parent) :
      mumeSrv{"ch.bitzgi.MumeSrv", "/ch/bitzgi/mumesrv", QDBusConnection::sessionBus(), parent}
    {
    }

    bool switchState() const override
    {
      return mumeSrv.switchOn();
    }

  private:
    ChBitzgiMumeSrvInterface mumeSrv;

};


int main(int argc, char *argv[])
{
  registerHttpTypes();

  QCoreApplication a{argc, argv};

  MumeDbus mumeSrv{&a};
  MumeWeb mumeweb{mumeSrv};

  FcgiServer server{&a};
  QObject::connect(&a, SIGNAL(aboutToQuit()), &server, SLOT(stop()));
  QObject::connect(&server, SIGNAL(accepted(HttpHeader, HttpData)), &mumeweb, SLOT(request(HttpHeader, HttpData)));
  server.start();

  auto const ret = a.exec();
  server.wait();
  return ret;
}

