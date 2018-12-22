#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pqrs/cf/number.hpp>

TEST_CASE("make_cf_number") {
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

TEST_CASE("make_number") {
  {
    int64_t value = 1099512677408LL; // 2^40 + 2^20 + 2^10 + 2^5
    auto number_ptr = pqrs::cf::make_cf_number(value);

    {
      auto n = pqrs::cf::make_number<int8_t>(*number_ptr);
      REQUIRE(n != std::nullopt);
      REQUIRE(*n == static_cast<int8_t>(value));
    }
    {
      auto n = pqrs::cf::make_number<int16_t>(*number_ptr);
      REQUIRE(n != std::nullopt);
      REQUIRE(*n == static_cast<int16_t>(value));
    }
    {
      auto n = pqrs::cf::make_number<int32_t>(*number_ptr);
      REQUIRE(n != std::nullopt);
      REQUIRE(*n == static_cast<int32_t>(value));
    }
    {
      auto n = pqrs::cf::make_number<int64_t>(*number_ptr);
      REQUIRE(n != std::nullopt);
      REQUIRE(*n == value);
    }
    {
      auto n = pqrs::cf::make_number<float>(*number_ptr);
      REQUIRE(n != std::nullopt);
      REQUIRE(*n == Approx(static_cast<float>(value)));
    }
    {
      auto n = pqrs::cf::make_number<double>(*number_ptr);
      REQUIRE(n != std::nullopt);
      REQUIRE(*n == Approx(static_cast<double>(value)));
    }
  }
}
