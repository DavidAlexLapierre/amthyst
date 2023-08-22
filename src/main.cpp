#include "engine/core/game.h"
#include "content/scenes/main_scene.h"

int main() {
    auto game = Game("Amethyst");
    game.registerScene(std::make_shared<Content::MainScene>("MainScene"));
    game.init();

    return 0;
}