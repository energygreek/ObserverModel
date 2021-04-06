#include "IObserver.hpp"
#include <iostream>
#include <memory>

class TestObserver: public IObserver, public std::enable_shared_from_this<TestObserver>{
public:
    TestObserver(std::shared_ptr<observe_interface> ptr, std::string topic):m_platform(ptr), m_topic(topic){
    }
    ~TestObserver(){
    }
    void register_topic(){
        m_platform->register_observer(m_topic,  shared_from_this());
    }
    void unregister_topic(){
        m_platform->unregister_observer(m_topic, shared_from_this());
    }
    void callback() override{
        std::cout << "new toptic message revieved\n";
    }

private:
    std::shared_ptr<observe_interface> m_platform;
    std::string m_topic;
};
