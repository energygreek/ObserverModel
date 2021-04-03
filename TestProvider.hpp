#include "IProvider.hpp"
#include <bits/stdint-uintn.h>

class TestProvider{
public:
    TestProvider(publish_interface* ptr, std::string topic):m_platform(ptr), m_topic(topic){
        m_platform->register_provider(m_topic);
    }
    ~TestProvider(){
        m_platform->unregister_provider(m_topic);
    }

    void send(){
        m_platform->send(m_topic);
    }

private:
    publish_interface* m_platform;
    std::string m_topic;
};