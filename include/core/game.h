#pragma once

#include <SDL2/SDL.h>
#include <memory>

namespace Core {
    class Game {
        public:
            Game();
            ~Game();
            void run();
        private:
            SDL_Window *window;
            SDL_Renderer *renderer;
            bool quit;
    };
}