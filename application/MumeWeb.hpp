// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef MUMEWEB_HPP
#define MUMEWEB_HPP

#include "IMumeDbus.hpp"

#include "http.hpp"

#include <QObject>
#include <QDomDocument>

class MumeWeb :
    public QObject
{
    Q_OBJECT

  public:
    MumeWeb(IMumeDbus &dbus);

  public slots:
    void request(HttpHeader header, HttpData data);

  private:
    IMumeDbus &dbus;

    void writeResponse(HttpHeader header, HttpData data);
    void readRequest(HttpHeader header, HttpData data);
    void parseRequest(const QDomElement request);
};

#endif // MUMEWEB_HPP
