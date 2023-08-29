#pragma once

#ifndef DATAORIENT_TEXTUREMANAGER_HPP
#define DATAORIENT_TEXTUREMANAGER_HPP

#include "headers.hpp"

class TextureManager{
public:
    static SDL_Texture* loadTexture(const char* fileName);
    static void Draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dest);
};

#endif //DATAORIENT_TEXTUREMANAGER_HPP
