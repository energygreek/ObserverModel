#include "TestObserver.hpp"
#include "TestProvider.hpp"
#include "platform.hpp"
#include <iostream>
#include <memory>

int main() {
  auto platform = std::make_shared<Platform>();

  auto topic1 = "topic1";
  auto topic2 = "topic2";
  auto topic3 = "topic3";

  TestProvider provider1(platform, topic1);
  TestProvider provider2(platform, topic2);
  TestProvider provider3(platform, topic3);

  auto observer1 = std::make_shared<TestObserver>(platform, topic1);
  auto observer2 = std::make_shared<TestObserver>(platform, topic2);
  auto observer3 = std::make_shared<TestObserver>(platform, topic3);
  auto observer1_1 = std::make_shared<TestObserver>(platform, topic1);

  observer1->register_topic();
  observer2->register_topic();
  observer3->register_topic();
  observer1_1->register_topic();

  provider1.send();
  provider2.send();
  provider3.send();

  observer1->unregister_topic();
  observer2->unregister_topic();
  observer3->unregister_topic();
  observer1_1->unregister_topic();

  return 0;
}
