#include "content/scenes/main_scene.h"

namespace Content {
    void MainScene::init() {
        createEntity(std::make_shared<Player>());
    }
}