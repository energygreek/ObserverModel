#include "IObserver.hpp"
#include <sys/types.h>
#include <iostream>

class TestObserver{
public:
    TestObserver(observer_interface* ptr, std::string topic):m_platform(ptr), m_topic(topic){
        m_platform->register_observer(m_topic,  [](){ std::cout << "new toptic message revieved\n";});
    }
    ~TestObserver(){
        m_platform->unregister_observer(m_topic,  [](){ std::cout << "new toptic message revieved\n";});
    }

private:
    observer_interface* m_platform;
    std::string m_topic;
};