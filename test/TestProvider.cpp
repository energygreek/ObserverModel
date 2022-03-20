#include <IObserver.hpp>
#include <gtest/gtest.h>

#include <platform.hpp>

TEST(TestProvider, Case1) {
  auto platform = std::make_shared<Platform>();

  const auto *topic1 = "topic1";
  platform->register_provider(topic1);

  ASSERT_TRUE(true);
}