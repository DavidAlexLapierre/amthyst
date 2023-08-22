#include "content/entities/player.h"
#include <iostream>

namespace Content {
    void Player::init() {
        auto mesh = Amethyst::MeshBuilder::createSprite();
        addComponent(mesh);
    }

    void Player::dispose() {

    }
}