#include <map>
#include <vector>

#include "IObserver.hpp"
#include "IProvider.hpp"

class Platform: public publish_interface, public observe_interface{
    std::map<std::string, std::vector<std::shared_ptr<IObserver>>> m_subscribtion;
public:
    void register_provider(std::string topic) override;
    void unregister_provider(std::string topic) override;
    void register_observer(std::string topic, std::shared_ptr<IObserver> observer ) override;
    void unregister_observer(std::string topic, std::shared_ptr<IObserver> observer ) override;
    void send(std::string topic) override;
};
