//
// Created by Jacob on 15/08/2020.
//

#include "Player.h"
#include "UserEvent.h"
#include <cmath>

PlayerStats            *playerStats      = new PlayerStats();

GameObject* playerAppearance;

void Player::renderPlayer(const char *texturesheet) {
    int Delta_x, Delta_y;
    int mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    Delta_x = playerStats->xpos - mouse_x;
    Delta_y = playerStats->ypos - mouse_y;
    double rotate = (atan2(Delta_y, Delta_x) * 180.0000)/ 3.14159265;

    playerAppearance = new GameObject(texturesheet, playerStats->xpos, playerStats->ypos, rotate);
    playerAppearance->Update();
    playerAppearance->Render();
}

void Player::updatePlayer(long double y = playerStats->ypos, long double x = playerStats->xpos) {

    playerStats->xpos += y;
    playerStats->ypos += x;

    //    srcRect.h = 64;
    //    srcRect.w = 64;
    //    srcRect.x = 0;
    //    srcRect.y = 0;
    //
    //    destRect.h = srcRect.h;
    //    destRect.w = srcRect.w;
    //    destRect.x = xpos;
    //    destRect.y = ypos;
}

PlayerStats::PlayerStats() {
    xpos;
    ypos;
}

