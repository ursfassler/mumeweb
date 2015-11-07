// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef FCGISUPPORT_HPP
#define FCGISUPPORT_HPP

#include <QMap>
#include <QString>

QMap<QString,QString> envToMap(const char * const * env);

#endif // FCGISUPPORT_HPP
