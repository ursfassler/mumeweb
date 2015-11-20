// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef IMUMEDBUS
#define IMUMEDBUS

class IMumeDbus
{
  public:
    virtual ~IMumeDbus() = default;

    virtual bool switchState() const = 0;

    virtual void setOpenPositionMs(double value) = 0;

};

#endif // IMUMEDBUS

