#pragma once

#include "engine/core/component.h"
#include "engine/core/entity.h"
#include "engine/data/uuid.h"
#include "engine/managers/system_manager.h"
#include <unordered_map>
#include <memory>
#include <typeindex>
#include <string>

namespace Amethyst {
    class SystemManager;
}

class System {
    public:
        System(std::shared_ptr<Amethyst::SystemManager> systemManager, std::vector<std::type_index> components);
        virtual void init() = 0;
        void createEntity(std::shared_ptr<Entity> entity);
        void registerEntity(std::shared_ptr<Entity> entity);
        void unregisterEntity(std::string id);
        virtual void update(double deltaT) = 0;
        std::vector<std::type_index> getComponents() const;

    private:
        std::vector<std::type_index> registeredComponents;

    protected:
        std::shared_ptr<Amethyst::SystemManager> systemManager;
        virtual void dispose() = 0;
        std::unordered_map<std::string, std::shared_ptr<Entity>> entities;
};