#include "core/game.h"

namespace Core {
    Game::Game() {
        // Initialize the different managers

        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            // Crash
        }

        window = SDL_CreateWindow(
            "Game",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            800,
            600,
            SDL_WINDOW_SHOWN);

        if (window == nullptr) {
            // Crash
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == nullptr) {
            // Creash
        }
    }

    Game::~Game() {
        // Destroy window and quit SDL
    }

    void Game::run() {
        // start the while loop
        SDL_Event event;
        int quit = 0;

        while (!quit) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    quit = 1;
                }
            }

            SDL_SetRenderDrawColor(renderer, 130, 28, 81, 255);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
        }
    }
}