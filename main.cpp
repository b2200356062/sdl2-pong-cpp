#include "game.hpp"

Game *game;

int main(int argc, char* argv[]) {

    const int FPS = 144.f;
    const float frameDelay = 1000.f / FPS;

    Uint64 frameStart;
    float frameTime;

    // top oyun basında rastgele bi tarafa ilerleyerek baslayacak
    // skor da olmalı - ui
    // collision detection ve movement
    // müzük belki

    game = new Game();

    game->init("pencere", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    game->load();

    while(game->running()){
        frameStart = SDL_GetTicks64();
        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks64() - frameStart;

//        if(frameDelay > frameTime / 1000.f){
//            SDL_Delay(frameDelay - frameTime);
//        }
    }
    game->clean();
    return 0;
}
