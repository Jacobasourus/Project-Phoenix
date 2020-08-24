//
// Created by Jacob on 15/08/2020.
//

#ifndef PROJECT_PHEONIX_PLAYER_H
#define PROJECT_PHEONIX_PLAYER_H

#include "GameObject.h"

class Player {
public:
    static void renderPlayer(const char* texturesheet);
    static void updatePlayer(long double y, long double x);
private:

};

class PlayerStats {
public:
    int xpos{};
    int ypos{};

    PlayerStats();
};

#endif //PROJECT_PHEONIX_PLAYER_H
