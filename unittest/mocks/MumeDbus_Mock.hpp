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
    MOCK_CONST_METHOD0(count, uint32_t());
    MOCK_METHOD1(setOpenPositionMs, void(double value));
    MOCK_METHOD1(setClosePositionMs, void(double value));
};

#endif // MUMEDBUS_MOCK

