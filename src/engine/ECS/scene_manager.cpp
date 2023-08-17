#include "engine/ECS/scene_manager.h"

namespace Engine::ECS {
    SceneManager::SceneManager() {

    }

    void SceneManager::registerScene(std::shared_ptr<Scene> scene) {
        auto name = scene.get()->getName();
        scenes[name] = scene;
    }
}