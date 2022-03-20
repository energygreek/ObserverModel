#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <memory>

class Abs {
public:
    virtual ~Abs() = default;
    virtual void foo() = 0;
};

class Concret : public Abs {
public:
    void foo() override {
        std::cout << "Concret\n" ;
    }
};

class Factory {
public:
    void factory_foo(std::shared_ptr<Abs> obj){
        obj->foo();
    }
};

class MockAbs:public Abs {
public:
  MOCK_METHOD(void, foo, (), (override));
};

TEST(TestExample, case1){
    auto mockabs = std::make_shared<MockAbs>();
    EXPECT_CALL(*mockabs, foo()).Times(testing::AtLeast(1));

    Factory factory;
    factory.factory_foo(mockabs);

}

TEST(TestExample, case2){
    auto mockabs = std::make_shared<Concret>();

    Factory factory;
    factory.factory_foo(mockabs);
}


