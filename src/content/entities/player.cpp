#include "content/entities/player.h"
#include <iostream>

namespace Content {
    void Player::init() {
        auto mesh = std::make_shared<Amethyst::Mesh>();
        mesh->geometry = Amethyst::Geometry();
        std::vector<float> vertices = {
            -0.5f, 0.5f, 0,
            -0.5f, -0.5f, 0,
            0.5f, -0.5f, 0,
            0.5f, -0.5f, 0,
            0.5f, 0.5f, 0,
            -0.5f, 0.5f, 0
        };
        mesh->geometry.vertices = vertices;
        addComponent(mesh);
    }

    void Player::dispose() {

    }
}