#pragma once

#include "engine/core/system.h"
#include "engine/core/entity.h"
#include "engine/utils/event_handler.h"
#include <vector>
#include <memory>
#include <typeindex>

namespace Engine::ECS {
    class SystemManager {
        public:
            SystemManager();
            void update(int deltaT);
            void registerSystem(std::shared_ptr<System> system);

        private:
            void addEntity(const void *data);
            bool entityMatchesSystem(std::shared_ptr<Entity> entity, std::shared_ptr<System> system);
            std::vector<std::shared_ptr<System>> systems;
    };
}