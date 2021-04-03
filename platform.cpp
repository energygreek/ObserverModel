#include "platform.hpp"
#include <algorithm>

void platform::register_provider(std::string topic){
    m_subscribtion.emplace(topic, std::vector<observer_callback>());
}
void platform::unregister_provider(std::string topic){
    auto it = m_subscribtion.find(topic);
    if(it != m_subscribtion.end()){
        m_subscribtion.erase(it);
    }
}
void platform::register_observer(std::string topic, observer_callback callback){
    auto it = m_subscribtion.find(topic);
    if(it != m_subscribtion.end()){
        it->second.emplace_back(callback);
    }
}
void platform::unregister_observer(std::string topic, observer_callback callback ){
    auto it = m_subscribtion.find(topic);
    if(it != m_subscribtion.end()){
        // auto call = std::find_if(it->second.begin(), it->second.end(), [&callback](auto cb){return cb == callback;});
        // if(call != it->second.end()){
        //     it->second.erase(call);
        // }
    }
}
void platform::send(std::string topic) {
    auto it = m_subscribtion.find(topic);
    if(it != m_subscribtion.end()){
        for(auto cb: it->second){
            cb();
        }
    }
}