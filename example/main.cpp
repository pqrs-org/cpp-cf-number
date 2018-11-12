#include <iostream>
#include <pqrs/cf_number.hpp>

int main(void) {
  if (auto number_ptr = pqrs::make_cf_number(static_cast<int32_t>(12345))) {
    int32_t value = 0;
    if (CFNumberGetValue(*number_ptr, kCFNumberSInt32Type, &value)) {
      std::cout << value << std::endl;
    }
  }

  return 0;
}
