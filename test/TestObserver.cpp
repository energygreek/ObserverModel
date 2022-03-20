#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>

#include <IObserver.hpp>
#include <platform.hpp>

// mock platform
struct MockObserver : public IObserver {
  MOCK_METHOD(void, callback, (), (override));
};

TEST(TestObserver, Case1) {
  auto platform = std::make_shared<Platform>();
  // auto *mockobserver = new MockObserver();
  std::shared_ptr<MockObserver>  mockobserver = std::make_shared<MockObserver>();
  EXPECT_CALL(*mockobserver, callback()).Times(testing::Exactly(1));

  const auto *topic1 = "topic1";
  platform->register_provider(topic1);
  platform->register_observer(topic1, mockobserver);
  platform->send(topic1);
  platform->unregister_observer(topic1, mockobserver);
}

TEST(TestObserver, Case2) {
  // GTEST_SKIP();
  auto platform = std::make_shared<Platform>();
  std::shared_ptr<MockObserver>  mockobserver = std::make_shared<MockObserver>();
  EXPECT_CALL(*mockobserver, callback()).Times(testing::Exactly(0));

  const auto *topic1 = "topic1";
  platform->register_provider(topic1);
  platform->register_observer(topic1, mockobserver);
  platform->unregister_observer(topic1, mockobserver);
  platform->send(topic1);

  platform->unregister_observer(topic1, mockobserver);
}