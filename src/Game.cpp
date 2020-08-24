//
// Created by Jacob on 9/08/2020.
//

#include "Game.h"
#include "UserEvent.h"
#include "Player.h"

SDL_Renderer *Game::renderer = nullptr;

Game::Game() = default;

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {

    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL Initialised!" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            std::cout << "Window created! " << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        isRunning = true;
    } else {
        isRunning = false;
    }

}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.key.keysym.scancode == SDL_SCANCODE_LSHIFT) {
        if (event.type == SDL_KEYUP) {
            UserEvent::User_KeyPress(16, 0);
        } else if (event.type == SDL_KEYDOWN) {
            UserEvent::User_KeyPress(16, 1);
        }
    }
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            UserEvent::User_KeyPress(event.key.keysym.sym, 1);
            break;
        case SDL_KEYUP:
            UserEvent::User_KeyPress(event.key.keysym.sym, 0);
            break;
        default:
            break;
    }
}

void Game::update() {
    long double speed = 4;
    long double speed_side = 0.75;

    if (UserEvent::KEY_SHIFT) {
        speed = 8;
    }

    if (UserEvent::KEY_PRESS_DOWN && UserEvent::KEY_PRESS_LEFT) {
        speed *= speed_side;
        Player::updatePlayer(-speed, speed);
    } else if (UserEvent::KEY_PRESS_DOWN && UserEvent::KEY_PRESS_RIGHT) {
        speed *= speed_side;
        Player::updatePlayer(speed, speed);
    } else if (UserEvent::KEY_PRESS_UP && UserEvent::KEY_PRESS_LEFT) {
        speed *= speed_side;
        Player::updatePlayer(-speed, -speed);
    } else if (UserEvent::KEY_PRESS_UP && UserEvent::KEY_PRESS_RIGHT) {
        speed *= speed_side;
        Player::updatePlayer(speed, -speed);
    } else {
        if (UserEvent::KEY_PRESS_UP) {
            Player::updatePlayer(0, -speed);
        }
        if (UserEvent::KEY_PRESS_DOWN) {
            Player::updatePlayer(0, speed);
        }
        if (UserEvent::KEY_PRESS_LEFT) {
            Player::updatePlayer(-speed, 0);
        }
        if (UserEvent::KEY_PRESS_RIGHT) {
            Player::updatePlayer(speed, 0);
        }
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    Player::renderPlayer("../assets/player.png");
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}
