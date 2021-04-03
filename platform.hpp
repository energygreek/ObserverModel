#include <map>
#include <vector>

#include "IObserver.hpp"
#include "IProvider.hpp"

class platform: public publish_interface, public observer_interface{
    std::map<std::string, std::vector<observer_callback> > m_subscribtion;
public:
    void register_provider(std::string topic) override;
    void unregister_provider(std::string topic) override;
    void register_observer(std::string topic, observer_callback callback) override;
    void unregister_observer(std::string topic, observer_callback callback ) override;
    void send(std::string topic) override;
};