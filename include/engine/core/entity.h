#pragma once

#include "engine/data/uuid.h"
#include "engine/core/component.h"
#include <typeindex>
#include <unordered_map>
#include <memory>
#include <vector>

class Entity {
    public:
        Entity();
        Data::UUID id();
        virtual void init() = 0;
        virtual void dispose() = 0;
        template <typename T>
        void addComponent(std::shared_ptr<T> component) {
            static_assert(std::is_base_of<Component, T>::value, "T must be derived from Component");
            components[typeid(T)] = component;
        }

        template <typename T>
        std::shared_ptr<T> getComponent() {
            static_assert(std::is_base_of<Component, T>::value, "T must be derived from Component");
            std::type_index typeIdx(typeid(T));
            auto it = components.find(typeIdx);
            if (it != components.end()) {
                return std::shared_ptr<T>(reinterpret_cast<T *>(it->second.get()));
            }
            return nullptr;
        }
        std::vector<std::type_index> getComponentList();
        std::unordered_map<std::type_index, std::shared_ptr<Component>> getComponents() const;

    private:
        std::unordered_map<std::type_index, std::shared_ptr<Component>> components;
        Data::UUID _id;
};