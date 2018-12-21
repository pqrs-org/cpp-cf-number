#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pqrs/cf/number.hpp>

TEST_CASE("cf_number") {
  {
    int8_t value = 100;
    auto number_ptr = pqrs::cf::make_cf_number(value);
    REQUIRE(number_ptr);
    REQUIRE(CFNumberGetByteSize(*number_ptr) == sizeof(value));
    REQUIRE(CFNumberGetValue(*number_ptr, kCFNumberSInt8Type, &value));
    REQUIRE(value == 100);
  }
  {
    int16_t value = 100;
    auto number_ptr = pqrs::cf::make_cf_number(value);
    REQUIRE(number_ptr);
    REQUIRE(CFNumberGetByteSize(*number_ptr) == sizeof(value));
    REQUIRE(CFNumberGetValue(*number_ptr, kCFNumberSInt16Type, &value));
    REQUIRE(value == 100);
  }
  {
    int32_t value = 100;
    auto number_ptr = pqrs::cf::make_cf_number(value);
    REQUIRE(number_ptr);
    REQUIRE(CFNumberGetByteSize(*number_ptr) == sizeof(value));
    REQUIRE(CFNumberGetValue(*number_ptr, kCFNumberSInt32Type, &value));
    REQUIRE(value == 100);
  }
  {
    int64_t value = 100;
    auto number_ptr = pqrs::cf::make_cf_number(value);
    REQUIRE(number_ptr);
    REQUIRE(CFNumberGetByteSize(*number_ptr) == sizeof(value));
    REQUIRE(CFNumberGetValue(*number_ptr, kCFNumberSInt64Type, &value));
    REQUIRE(value == 100);
  }
  {
    float value = 100.0f;
    auto number_ptr = pqrs::cf::make_cf_number(value);
    REQUIRE(number_ptr);
    REQUIRE(CFNumberGetByteSize(*number_ptr) == sizeof(value));
    REQUIRE(CFNumberGetValue(*number_ptr, kCFNumberFloat32Type, &value));
    REQUIRE(value == Approx(100.0f));
  }
  {
    double value = 100.0;
    auto number_ptr = pqrs::cf::make_cf_number(value);
    REQUIRE(number_ptr);
    REQUIRE(CFNumberGetByteSize(*number_ptr) == sizeof(value));
    REQUIRE(CFNumberGetValue(*number_ptr, kCFNumberFloat64Type, &value));
    REQUIRE(value == Approx(100.0));
  }
}
