#include "platform.hpp"
#include "TestObserver.hpp"
#include "TestProvider.hpp"

int main(){
    platform platform;

    auto topic1 = "topic1";
    auto topic2 = "topic2";
    auto topic3 = "topic3";


    TestProvider provider1(&platform, topic1);
    TestProvider provider2(&platform, topic2);
    TestProvider provider3(&platform, topic3);
    
    TestObserver observer1(&platform, topic1);
    TestObserver observer2(&platform, topic2);
    TestObserver observer3(&platform, topic3);
    TestObserver observer1_1(&platform, topic1);


    provider1.send();
    provider2.send();
    provider3.send();

    return 0;
}