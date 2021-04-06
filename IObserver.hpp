#ifndef IOBSERVER_
#define IOBSERVER_
#include <string>
#include <memory>

class IObserver{
public:
  virtual void callback() = 0;
  virtual ~IObserver()= default;
};

class observer_interface{
public:
    virtual void register_observer(std::string topic, std::shared_ptr<IObserver> observer ) = 0;
    virtual void unregister_observer(std::string topic, std::shared_ptr<IObserver> observer ) = 0;
    virtual ~observer_interface() = default;
};

#endif
