// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "http.hpp"

void registerHttpTypes()
{
  qRegisterMetaType<HttpHeader>("HttpHeader");
  qRegisterMetaType<HttpData>("HttpData");
}
