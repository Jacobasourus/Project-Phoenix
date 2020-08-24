//
// Created by Jacob on 11/08/2020.
//

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y, double r) {

    objTexture = TextureManager::LoadTexture(texturesheet);

    xpos = x - 32;
    ypos = y - 32;
    angle = r + 90;
}

void GameObject::Update() {

    srcRect.h = 64;
    srcRect.w = 64;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.h = srcRect.h;
    destRect.w = srcRect.w;
    destRect.x = xpos;
    destRect.y = ypos;
}

void GameObject::Render() {
    SDL_RenderCopyEx(Game::renderer, objTexture, &srcRect, &destRect, angle, &center, SDL_FLIP_NONE);
}

GameObject::~GameObject() = default;
