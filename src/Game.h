//
// Created by Jacob on 9/08/2020.
//

#ifndef Game_h
#define Game_h

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_error.h"
#include <iostream>

class Game {

public:
    Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    static void update();
    static void render();
    void clean();

    [[nodiscard]] bool running() const {
        return isRunning;
    }

    static SDL_Renderer* renderer;

private:
    int cnt = 0;
    bool isRunning = false;
    SDL_Window* window{};
};

#endif
