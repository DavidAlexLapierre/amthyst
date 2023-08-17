#pragma once

#include "engine/core/scene.h"

namespace Content {
    class MainScene : public Scene {
        public:
            MainScene(const std::string& name) : Scene(name) {}
            ~MainScene();
            void init() override;
            void dispose() override;
    };
}