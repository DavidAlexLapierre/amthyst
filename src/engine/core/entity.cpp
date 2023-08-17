#include "engine/core/entity.h"

Entity::Entity() {
    _id = Data::UUID();
}

template <typename T>
void Entity::addComponent(std::shared_ptr<T> component) {
    static_assert(std::is_base_of<Component, T>::value, "T must be derived from Component");
    components[typeid(T)] = component;
}

template <typename T>
std::shared_ptr<T> Entity::getComponent() {
    static_assert(std::is_base_of<Component, T>::value, "T must be derived from Component");
    std::type_index typeIdx(typeid(T));
    auto it = components.find(typeIdx);
    if (it != components.end()) {
        return dynamic_cast<T*>(it->second.get());
    }
    return nullptr;
}