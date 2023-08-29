
#include "game.hpp"
#include "player.hpp"
#include "ball.hpp"

SDL_Renderer* Game::renderer = nullptr;

Game::Game() {
    std::default_random_engine e((unsigned int)time(0));
    random = e() % 2;
}

Game::~Game() {
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, int flags) {

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        cout << "cannout init sdl" << endl;
        isRunning = false;
        return;
    }

    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if(!window){
        cout << "cannot create window" << endl;
        isRunning = false;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    if(!renderer){
        cout << "cannot create renderer" << endl;
        isRunning = false;
        return;
    }

    SDL_SetRenderDrawColor(renderer,0,0,0,255);

    if(random == 0){
        // ball movement
    }
    else{

    }

    isRunning = true;
}

Player* player1 = nullptr;
Ball* ball = nullptr;
Player* player2 = nullptr;

void Game::load() {
    player1 = new Player(48, 320, "assets/pong1.png");
    player2 = new Player(700, 320, "assets/pong1.png");
    ball = new Ball(370, 320, "assets/pong2.png");
}

void Game::handleEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0){
        switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE){
                    isRunning = false;
                    break;
                }
                else if(event.key.keysym.sym == SDLK_w && event.key.repeat == 0){
                    player1->yvel -= PLAYER_VELOCITY;
                    break;
                }
                else if(event.key.keysym.sym == SDLK_s && event.key.repeat == 0){
                    player1->yvel += PLAYER_VELOCITY;
                    break;
                }
                else if(event.key.keysym.sym == SDLK_UP && event.key.repeat == 0 ){
                    player2->yvel -= PLAYER_VELOCITY;
                    break;
                }
                else if(event.key.keysym.sym == SDLK_DOWN && event.key.repeat == 0 ){
                    player2->yvel += PLAYER_VELOCITY;
                    break;
                }
                break;

            case SDL_KEYUP:
                if(event.key.keysym.sym == SDLK_w && event.key.repeat == 0){
                    player1->yvel += PLAYER_VELOCITY;
                    break;
                }
                else if(event.key.keysym.sym == SDLK_s && event.key.repeat == 0){
                    player1->yvel -= PLAYER_VELOCITY;
                    break;
                }
                else if(event.key.keysym.sym == SDLK_UP && event.key.repeat == 0){
                    player2->yvel += PLAYER_VELOCITY;
                    break;
                }
                else if(event.key.keysym.sym == SDLK_DOWN && event.key.repeat == 0){
                    player2->yvel -= PLAYER_VELOCITY;
                    break;
                }
                break;
            default:
                break;
        }
    }
}

void Game::update() {
    player1->update();
    player2->update();
    ball->update();

    player1->checkCollision(ball);
    player2->checkCollision(ball);
    // ui update
}

void Game::render() {
    SDL_RenderClear(renderer);
    player1->render();
    ball->render();
    player2->render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    delete player1;
    delete player2;
    delete ball;
    player1 = nullptr;
    player2 = nullptr;
    ball = nullptr;
    renderer = nullptr;
    window = nullptr;
    SDL_Quit();
    cout << "cleaned" << endl;
}
