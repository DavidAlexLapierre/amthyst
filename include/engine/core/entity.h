#pragma once

#include "engine/data/uuid.h"
#include "engine/core/component.h"
#include <typeindex>
#include <map>
#include <memory>
#include <vector>

class Entity {
    public:
        Entity();
        Data::UUID id();
        virtual void init() = 0;
        virtual void dispose() = 0;
        template <typename T>
        void addComponent(std::shared_ptr<T> component);
        template <typename T>
        std::shared_ptr<T> getComponent();
        std::vector<std::type_index> getComponentList();
        std::map<std::type_index, std::shared_ptr<Component>> getComponents() const;

    private:
        std::map<std::type_index, std::shared_ptr<Component>> components;
        Data::UUID _id;
};