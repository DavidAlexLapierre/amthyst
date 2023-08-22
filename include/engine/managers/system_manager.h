#pragma once

#include "engine/rendering/renderer.h"
#include "engine/core/system.h"
#include "engine/core/entity.h"
#include <vector>
#include <memory>
#include <typeindex>

class System;

namespace Amethyst {
    class SystemManager {
        public:
            SystemManager();
            void update(double deltaT);
            void draw();
            void createEntity(std::shared_ptr<Entity> entity);
            void registerSystem(std::shared_ptr<System> system);
            std::vector<std::shared_ptr<System>> getSystems();

        private:
            std::shared_ptr<Amethyst::Renderer> renderer;
            bool entityMatchesSystem(std::shared_ptr<Entity> entity, std::shared_ptr<System> system);
            std::vector<std::shared_ptr<System>> systems;
    };
}