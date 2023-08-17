#include "engine/core/game.h"
#include "content/scenes/main_scene.h"
#include <memory>

int main() {
    
    std::unique_ptr<Game> game(new Game());
    game->registerScene(std::make_shared<Content::MainScene>("MainScene"));
    game->run();

    return 0;
}