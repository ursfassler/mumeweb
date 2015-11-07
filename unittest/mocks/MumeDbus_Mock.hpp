// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef MUMEDBUS_MOCK
#define MUMEDBUS_MOCK

#include <IMumeDbus.hpp>
#include <gmock/gmock.h>

class MumeDbusMock : public IMumeDbus
{
  public:
    MOCK_CONST_METHOD0(switchState, bool());
};

#endif // MUMEDBUS_MOCK

