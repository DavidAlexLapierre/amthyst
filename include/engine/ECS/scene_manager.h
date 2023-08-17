#pragma once

#include "engine/core/scene.h"
#include <map>
#include <memory>
#include <string>

namespace Engine::ECS {
    class SceneManager {
        public:
            SceneManager();
            void registerScene(std::shared_ptr<Scene> scene);

        private:
            std::map<std::string, std::shared_ptr<Scene>> scenes;
    };
}