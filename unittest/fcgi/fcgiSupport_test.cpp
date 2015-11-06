#include <fcgi/fcgiSupport.hpp>

#include "mocks/MumeDbus_Mock.hpp"

#include <gtest/gtest.h>

#include <QMap>
#include <QString>

namespace
{

  TEST(fcgiSupport_envToMap, convert_normal_key_value_list_to_map)
  {
    const char *list[] = { "a=b", "test=123", "01=hallo", nullptr };
    const QMap<QString,QString> expected{ {"a", "b"}, {"test", "123"}, {"01", "hallo"} };

    const auto map = envToMap(list);

    ASSERT_EQ(expected, map);
  }

  TEST(fcgiSupport_envToMap, handle_key_with_missing_value)
  {
    const char *list[] = { "abc=", nullptr };
    const QMap<QString,QString> expected{ {"abc", ""} };

    const auto map = envToMap(list);

    ASSERT_EQ(expected, map);
  }

  TEST(fcgiSupport_envToMap, handle_entry_with_no_separator)
  {
    const char *list[] = { "abc", nullptr };
    const QMap<QString,QString> expected{ {"abc", ""} };

    const auto map = envToMap(list);

    ASSERT_EQ(expected, map);
  }

  TEST(fcgiSupport_envToMap, handle_entry_with_multiple_separator)
  {
    const char *list[] = { "a=b=c=d=e", nullptr };
    const QMap<QString,QString> expected{ {"a", "b=c=d=e"} };

    const auto map = envToMap(list);

    ASSERT_EQ(expected, map);
  }

  TEST(fcgiSupport_envToMap, handle_entry_with_no_key)
  {
    const char *list[] = { "=abc", nullptr };
    const QMap<QString,QString> expected{ {"", "abc"} };

    const auto map = envToMap(list);

    ASSERT_EQ(expected, map);
  }

  TEST(fcgiSupport_envToMap, entry_with_no_key_nor_value_is_ignored)
  {
    const char *list[] = { "=", nullptr };
    const QMap<QString,QString> expected{};

    const auto map = envToMap(list);

    ASSERT_EQ(expected, map);
  }

  TEST(fcgiSupport_envToMap, empty_entry_is_ignored)
  {
    const char *list[] = { "", nullptr };
    const QMap<QString,QString> expected{};

    const auto map = envToMap(list);

    ASSERT_EQ(expected, map);
  }

  TEST(fcgiSupport_envToMap, same_key_throws_exception)
  {
    const char *list[] = { "a=1", "b=2", "a=3", nullptr };

    ASSERT_THROW(envToMap(list), std::invalid_argument);
  }
}
