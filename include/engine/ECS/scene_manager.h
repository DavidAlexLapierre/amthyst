#pragma once

#include "engine/core/scene.h"
#include <unordered_map>
#include <memory>
#include <string>

namespace Engine::ECS {
    class SceneManager {
        public:
            SceneManager();
            ~SceneManager();
            void registerScene(std::shared_ptr<Scene> scene);
            std::shared_ptr<Scene> getCurrentScene();
            void setScene(const std::string& name);

        private:
            std::shared_ptr<Scene> currentScene;
            std::unordered_map<std::string, std::shared_ptr<Scene>> scenes;
    };
}