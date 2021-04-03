#ifndef IOBSERVER_
#define IOBSERVER_
#include <functional>
#include <string>

class observer_interface{
public:
    using observer_callback = std::function<void(void)>;
    virtual void register_observer(std::string topic, observer_callback callback ) = 0;
    virtual void unregister_observer(std::string topic, observer_callback callback ) = 0;
    ~observer_interface() =default;
};

#endif