#include "engine/core/entity.h"

Entity::Entity() {
    _id = Amethyst::UUID();
}

Amethyst::UUID Entity::id() { return _id; }

std::vector<std::type_index> Entity::getComponentList() {
    std::vector<std::type_index> _components;
    for (auto component : components) {
        _components.push_back(component.first);
    }

    return _components;
}

std::unordered_map<std::type_index, std::shared_ptr<Component>> Entity::getComponents() const { return components; }