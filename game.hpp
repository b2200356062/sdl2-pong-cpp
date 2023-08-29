#pragma once

#ifndef DATAORIENT_GAME_HPP
#define DATAORIENT_GAME_HPP

#include "headers.hpp"
#include "texturemanager.hpp"
#include "gameobject.hpp"

class Game{
public:
    Game();
    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, int flags);

    void handleEvents();
    void load();
    void update();
    void render();
    void clean();
    bool running() { return isRunning; }

    static SDL_Renderer* renderer;
    int random;

private:
    bool isRunning;
    SDL_Window *window;
};

#endif //DATAORIENT_GAME_HPP
