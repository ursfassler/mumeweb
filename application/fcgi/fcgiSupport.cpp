// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "fcgiSupport.hpp"

#include <QPair>

static bool found(int index)
{
  return index >= 0;
}

static QPair<QString,QString> split(QString line)
{
  const auto idx = line.indexOf("=");
  if (found(idx)) {
    const auto key = line.left(idx);
    const auto value = line.right(line.size()-idx-1);
    return {key, value};
  } else {
    return {line, ""};
  }
}

static bool isEmpty(QPair<QString,QString> entry)
{
  return entry == QPair<QString,QString>{};
}

QMap<QString, QString> envToMap(const char * const * env)
{
  QMap<QString, QString> map{};

  for (const char * const * str = env; *str != nullptr; str++) {
    const QString line{*str};
    const auto entry = split(line);
    if (!isEmpty(entry)) {
      if (map.contains(entry.first)) {
        throw std::invalid_argument("entry with key " + entry.first.toStdString() + " already in map");
      }
      map.insert(entry.first, entry.second);
    }
  }

  return map;
}
