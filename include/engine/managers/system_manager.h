#pragma once

#include "engine/core/system.h"
#include "engine/core/entity.h"
#include <vector>
#include <memory>
#include <typeindex>

class System;

namespace Engine::Managers {
    class SystemManager {
        public:
            SystemManager() {}
            void update(double deltaT);
            void createEntity(std::shared_ptr<Entity> entity);
            void registerSystem(std::shared_ptr<System> system);
            std::vector<std::shared_ptr<System>> getSystems();

        private:
            bool entityMatchesSystem(std::shared_ptr<Entity> entity, std::shared_ptr<System> system);
            std::vector<std::shared_ptr<System>> systems;
    };
}