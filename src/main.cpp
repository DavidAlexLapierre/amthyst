#include "engine/core/game.h"
#include <memory>

int main() {
    
    std::unique_ptr<Game> game(new Game());
    game->run();

    return 0;
}