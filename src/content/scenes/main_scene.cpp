#include "content/scenes/main_scene.h"
#include <iostream>

namespace Content {
    void MainScene::init() {
        createEntity(std::make_shared<Player>());
    }

    void MainScene::dispose() {
    }
}