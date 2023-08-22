#include "content/entities/player.h"
#include <iostream>

namespace Content {
    void Player::init() {
        addComponent(Amethyst::MeshBuilder::createSprite());
    }

    void Player::dispose() {

    }
}