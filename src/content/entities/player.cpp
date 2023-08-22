#include "content/entities/player.h"

namespace Content {
    void Player::init() {
        addComponent(Amethyst::MeshBuilder::createSprite());
    }
}