#include "content/entities/player.h"
#include <iostream>

namespace Content {
    void Player::init() {
        auto mesh = std::make_shared<Engine::Rendering::Mesh>();
        addComponent(mesh);
    }

    void Player::dispose() {

    }
}