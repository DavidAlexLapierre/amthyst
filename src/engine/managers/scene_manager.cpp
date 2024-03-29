#include "engine/managers/scene_manager.h"

namespace Amethyst {
    SceneManager::SceneManager() {
        currentScene = nullptr;
    }

    void SceneManager::dispose() {
        for (const auto& scene : scenes) {
            scene.second->dispose();
        }
    }

    void SceneManager::registerScene(std::shared_ptr<Scene> scene) {
        auto name = scene.get()->getName();
        scenes[name] = scene;
        if (currentScene == nullptr) { setScene(scene->getName()); }
    }

    void SceneManager::setScene(const std::string& name) {
        if (scenes.find(name) != scenes.end()) {
            if (currentScene != nullptr) { currentScene->dispose(); }
            currentScene = scenes[name];
            currentScene->init();
        }
    }

    std::shared_ptr<Scene> SceneManager::getCurrentScene() { return currentScene; }
}