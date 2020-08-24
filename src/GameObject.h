#pragma once
#include "Game.h"

class GameObject {

public:
    GameObject(const char* texturesheet, int x, int y, double r);
    ~GameObject();

    void Update();
    void Render();

private:

    int xpos;
    int ypos;
    int angle;
    const SDL_Point center = {32, 32};

    SDL_Texture* objTexture;
    SDL_Rect srcRect{}, destRect{};


};