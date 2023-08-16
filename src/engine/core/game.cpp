#include "engine/core/game.h"
#include <iostream>

namespace Engine::Core {
    Game::Game() {

    }

    void Game::run() {
        std::cout << "Hello world!" << std::endl;
    }
}