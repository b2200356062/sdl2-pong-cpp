#pragma once

#ifndef DATAORIENT_GAMEOBJECT_HPP
#define DATAORIENT_GAMEOBJECT_HPP

#include "headers.hpp"
#include "texturemanager.hpp"

class GameObject{
public:
    GameObject();

    virtual ~GameObject();

    virtual void update() = 0;
    virtual void render(SDL_Renderer *renderer) = 0;
    void checkCollision(GameObject* object1);

    float yvel;
    float xvel;

    bool isCollided;

    int width;
    int height;

    float ypos;
    float xpos;

    SDL_Texture* objectTexture;
    SDL_Rect srcRect, destRect, resultRect;
};

#endif //DATAORIENT_GAMEOBJECT_HPP
