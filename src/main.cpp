#include "engine/core/game.h"
#include <memory>

int main() {
    
    std::unique_ptr<Engine::Core::Game> game(new Engine::Core::Game());
    game->run();

    return 0;
}