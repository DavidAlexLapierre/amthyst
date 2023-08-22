#pragma once

#include "engine/core/scene.h"
#include <unordered_map>
#include <memory>
#include <string>

namespace Amethyst {
    class SceneManager {
        public:
            SceneManager();
            void registerScene(std::shared_ptr<Scene> scene);
            std::shared_ptr<Scene> getCurrentScene();
            void setScene(const std::string& name);
            void dispose();

        private:
            std::shared_ptr<Scene> currentScene;
            std::unordered_map<std::string, std::shared_ptr<Scene>> scenes;
    };
}