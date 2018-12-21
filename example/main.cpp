#include <iostream>
#include <pqrs/cf/number.hpp>

int main(void) {
  if (auto number_ptr = pqrs::cf::make_cf_number(static_cast<int32_t>(12345))) {
    int32_t value = 0;
    if (CFNumberGetValue(*number_ptr, kCFNumberSInt32Type, &value)) {
      std::cout << value << std::endl;
    }
  }

  return 0;
}
