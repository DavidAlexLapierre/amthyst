#pragma once

#include "engine/core/scene.h"
#include "content/entities/player.h"

namespace Content {
    class MainScene : public Scene {
        public:
            MainScene(const std::string name) : Scene(name) {}
            void init() override;
    };
}