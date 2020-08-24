#include "src/Game.h"

Game *game = nullptr;

int main(int argc, char *argv[]) {

    const int FPS       = 60;
    int       WinWidth  = 1280;
    int       WinHeight = 720;

    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int    frameTime;

    game = new Game();

    game->init("Project Phoenix", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WinWidth, WinHeight, false);


    while (game->running()) {

        frameStart = SDL_GetTicks();

        game->handleEvents();
        Game::update();

        Game::render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }

    }

    game->clean();

    return 0;
}