
#include "texturemanager.hpp"
#include "game.hpp"

SDL_Texture *TextureManager::loadTexture(const char *fileName) {

    SDL_Texture *tex = IMG_LoadTexture(Game::renderer, fileName);

    if(!tex){
        cout << "texture cannot be loaded" << endl;
        return nullptr;
    }

    return tex;
}

void TextureManager::Draw(SDL_Texture *text, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(Game::renderer, text, &src, &dest);
}
