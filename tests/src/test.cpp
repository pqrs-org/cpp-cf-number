#include <boost/ut.hpp>
#include <pqrs/cf/number.hpp>

int main(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "make_cf_number"_test = [] {
    {
      int8_t value = 100;
      auto number_ptr = pqrs::cf::make_cf_number(value);
      expect(number_ptr);
      expect(CFNumberGetByteSize(*number_ptr) == sizeof(value));
      expect(CFNumberGetValue(*number_ptr, kCFNumberSInt8Type, &value));
      expect(value == 100);
    }
    {
      int16_t value = 100;
      auto number_ptr = pqrs::cf::make_cf_number(value);
      expect(number_ptr);
      expect(CFNumberGetByteSize(*number_ptr) == sizeof(value));
      expect(CFNumberGetValue(*number_ptr, kCFNumberSInt16Type, &value));
      expect(value == 100);
    }
    {
      int32_t value = 100;
      auto number_ptr = pqrs::cf::make_cf_number(value);
      expect(number_ptr);
      expect(CFNumberGetByteSize(*number_ptr) == sizeof(value));
      expect(CFNumberGetValue(*number_ptr, kCFNumberSInt32Type, &value));
      expect(value == 100);
    }
    {
      int64_t value = 100;
      auto number_ptr = pqrs::cf::make_cf_number(value);
      expect(number_ptr);
      expect(CFNumberGetByteSize(*number_ptr) == sizeof(value));
      expect(CFNumberGetValue(*number_ptr, kCFNumberSInt64Type, &value));
      expect(value == 100);
    }
    {
      float value = 100.0f;
      auto number_ptr = pqrs::cf::make_cf_number(value);
      expect(number_ptr);
      expect(CFNumberGetByteSize(*number_ptr) == sizeof(value));
      expect(CFNumberGetValue(*number_ptr, kCFNumberFloat32Type, &value));
      expect(value == 100.0_f);
    }
    {
      double value = 100.0;
      auto number_ptr = pqrs::cf::make_cf_number(value);
      expect(number_ptr);
      expect(CFNumberGetByteSize(*number_ptr) == sizeof(value));
      expect(CFNumberGetValue(*number_ptr, kCFNumberFloat64Type, &value));
      expect(value == 100.0_d);
    }
  };

  "make_number"_test = [] {
    {
      auto n = pqrs::cf::make_number<int8_t>(nullptr);
      expect(n == std::nullopt);
    }

    {
      auto n = pqrs::cf::make_number<int8_t>(CFSTR("1234"));
      expect(n == std::nullopt);
    }

    {
      int64_t value = 1099512677408LL; // 2^40 + 2^20 + 2^10 + 2^5
      auto number_ptr = pqrs::cf::make_cf_number(value);

      {
        auto n = pqrs::cf::make_number<int8_t>(*number_ptr);
        expect(n != std::nullopt);
        expect(*n == static_cast<int8_t>(value));
      }
      {
        auto n = pqrs::cf::make_number<int16_t>(*number_ptr);
        expect(n != std::nullopt);
        expect(*n == static_cast<int16_t>(value));
      }
      {
        auto n = pqrs::cf::make_number<int32_t>(*number_ptr);
        expect(n != std::nullopt);
        expect(*n == static_cast<int32_t>(value));
      }
      {
        auto n = pqrs::cf::make_number<int64_t>(*number_ptr);
        expect(n != std::nullopt);
        expect(*n == value);
      }
      {
        auto n = pqrs::cf::make_number<float>(*number_ptr);
        expect(n != std::nullopt);
        expect(*n == static_cast<float>(value));
      }
      {
        auto n = pqrs::cf::make_number<double>(*number_ptr);
        expect(n != std::nullopt);
        expect(*n == static_cast<double>(value));
      }
    }
  };

  return 0;
}
