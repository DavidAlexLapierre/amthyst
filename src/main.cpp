#include "engine/core/game.h"
#include "content/scenes/main_scene.h"
#include <memory>

int main() {
    auto game = Game();
    game.registerScene(std::make_shared<Content::MainScene>("MainScene"));
    game.init();

    return 0;
}