// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef IMUMEDBUS
#define IMUMEDBUS

#include <cstdint>

class IMumeDbus
{
  public:
    virtual ~IMumeDbus() = default;

    virtual bool switchState() const = 0;
    virtual uint32_t count() const = 0;

    virtual void setOpenPositionMs(double value) = 0;

};

#endif // IMUMEDBUS

