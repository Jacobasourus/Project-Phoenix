#include "TextureManager.h"
#include <string>

SDL_Texture* TextureManager::LoadTexture(const char * filePath) {

    SDL_Texture *texture;
    SDL_Surface *surface = IMG_Load(filePath);
    if (surface == nullptr) {
        std::cout << "surface error: '" << IMG_GetError() << std::endl;
    }
    texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
    if (texture == nullptr) {
        std::cout << "texture error: " <<SDL_GetError() << std::endl;
    }
    SDL_FreeSurface(surface);

    return texture;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest){
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}