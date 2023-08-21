#include "content/entities/player.h"
#include <iostream>

namespace Content {
    void Player::init() {
        //auto mesh = std::make_shared<Engine::Rendering::Mesh>();
        //addComponent(mesh);
        std::cout << "Hello player" << std::endl;
    }

    void Player::dispose() {

    }
}