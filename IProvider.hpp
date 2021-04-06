#ifndef IPROVIDER_
#define IPROVIDER_

#include <string>

class publish_interface{
public:
    virtual void send(std::string topic) =  0;
    virtual void register_provider(std::string topic) = 0;
    virtual void unregister_provider(std::string topic) = 0;
    virtual ~publish_interface() = default;
};

#endif
