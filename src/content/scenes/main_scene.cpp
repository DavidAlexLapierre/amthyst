#include "content/scenes/main_scene.h"
#include <iostream>

namespace Content {

    MainScene::~MainScene() {
        dispose();
    }

    void MainScene::init() {
        std::cout << "Creating scene" << std::endl;
    }

    void MainScene::dispose() {
        std::cout << "Disposing scene" << std::endl;
    }
}