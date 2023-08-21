#pragma once

#include "engine/core/system.h"
#include "engine/core/entity.h"
#include "engine/core/scene.h"
#include <vector>
#include <memory>
#include <typeindex>

class Scene;

namespace Engine::Managers {
    class SystemManager {
        public:
            SystemManager() {}
            SystemManager(std::shared_ptr<Scene> _scene);
            void update(double deltaT);
            void createEntity(std::shared_ptr<Entity> entity);
            void registerSystem(std::shared_ptr<System> system);
            std::vector<std::shared_ptr<System>> getSystems();

        private:
            std::shared_ptr<Scene> scene;
            bool entityMatchesSystem(std::shared_ptr<Entity> entity, std::shared_ptr<System> system);
            std::vector<std::shared_ptr<System>> systems;
    };
}