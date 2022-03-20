#include "platform.hpp"
#include <algorithm>

void Platform::register_provider(std::string topic) {
  m_subscribtion.emplace(topic, std::vector<std::shared_ptr<IObserver>>());
}
void Platform::unregister_provider(std::string topic) {
  auto it = m_subscribtion.find(topic);
  if (it != m_subscribtion.end()) {
    m_subscribtion.erase(it);
  }
}
void Platform::register_observer(std::string topic,
                                 std::shared_ptr<IObserver> observer) {

  auto it = m_subscribtion.find(topic);
  if (it != m_subscribtion.end()) {
    it->second.emplace_back(observer);
  }
}
void Platform::unregister_observer(std::string topic,
                                   std::shared_ptr<IObserver> observer) {

  auto it = m_subscribtion.find(topic);
  if (it != m_subscribtion.end()) {
    auto result = std::find(it->second.begin(), it->second.end(), observer);
    if(result != it->second.end()){
      it->second.erase(result);
    }
  }
}
void Platform::send(std::string topic) {

  auto it = m_subscribtion.find(topic);
  if (it != m_subscribtion.end()) {
    for (auto &observer : it->second) {
      observer->callback();
    }
  }
}
