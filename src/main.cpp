#include <iostream>
#include <memory>
#include <platform.hpp>

int main() {
  auto platform = std::make_shared<Platform>();

  auto topic1 = "topic1";
  auto topic2 = "topic2";
  auto topic3 = "topic3";

  return 0;
}
