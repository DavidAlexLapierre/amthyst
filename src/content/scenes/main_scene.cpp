#include "content/scenes/main_scene.h"
#include <iostream>

namespace Content {
    void MainScene::init() {
        std::cout << "Creating scene" << std::endl;
        setColor(Data::Color(255, 0, 255));
    }

    void MainScene::dispose() {
        std::cout << "Disposing scene" << std::endl;
    }
}