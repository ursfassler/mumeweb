// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef HTTP
#define HTTP

#include <QMap>
#include <QString>
#include <QSharedPointer>
#include <QIODevice>

static const QString HttpLineEnd{"\r\n"};
static const QString HttpHeaderSeparator{HttpLineEnd + HttpLineEnd};

typedef QMap<QString,QString> HttpHeader;
Q_DECLARE_METATYPE(HttpHeader)

typedef QSharedPointer<QIODevice> HttpData;
Q_DECLARE_METATYPE(HttpData)

void registerHttpTypes();

#endif // HTTP

