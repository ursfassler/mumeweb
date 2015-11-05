#include "Calculator.h"

#include <gtest/gtest.h>


TEST(Calculator, add_2_numbers)
{
  Calculator testee;

  testee.push(12.34);
  testee.push(56.78);

  EXPECT_DOUBLE_EQ(69.12, testee.add());
}
