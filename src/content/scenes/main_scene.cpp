#include "content/scenes/main_scene.h"
#include <iostream>

namespace Content {
    void MainScene::init() {
        auto player = std::make_shared<Player>();
        systemManager->createEntity(player);
    }

    void MainScene::dispose() {
    }
}