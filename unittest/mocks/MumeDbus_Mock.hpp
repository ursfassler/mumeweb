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

