#include "core/game.h"
#include <memory>

int main(int argc, char *argv[]) {

    std::unique_ptr<Core::Game> game = std::make_unique<Core::Game>();
    game->run();
    
    return 0;
}