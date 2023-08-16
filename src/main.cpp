#include "engine/core/game.h"
#include <memory>

int main() {
    
    std::unique_ptr<Core::Game> game(new Core::Game());
    game->run();

    return 0;
}