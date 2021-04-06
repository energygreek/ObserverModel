#include "IProvider.hpp"
#include <memory>

class TestProvider{
public:
    TestProvider(std::shared_ptr<publish_interface> ptr, std::string topic):m_platform(ptr), m_topic(topic){
        m_platform->register_provider(m_topic);
    }
    ~TestProvider(){
        m_platform->unregister_provider(m_topic);
    }

    void send(){
        m_platform->send(m_topic);
    }

private:
    std::shared_ptr<publish_interface> m_platform;
    std::string m_topic;
};