
#include "ball.hpp"

Ball::Ball(float posx, float posy, const std::string& fileName) {
    objectTexture = TextureManager::loadTexture(fileName.c_str());

    this->xpos = posx;
    this->ypos = posy;

    this->yvel = 0;
    this->xvel = 0;

    SDL_QueryTexture(objectTexture, nullptr, nullptr, &width, &height);

    this->srcRect.x = 32;
    this->srcRect.y = 16;
    this->srcRect.h = height;
    this->srcRect.w = width;

    this->destRect.x = int(xpos);
    this->destRect.y = int(ypos);
    this->destRect.h = 48;
    this->destRect.w = 32;

}

void Ball::update() {

    ypos += yvel;

    if(ypos < 0 || ypos > SCREEN_HEIGHT){
        ypos -= yvel;
    }

    xpos += xvel;

    if(xpos < 0 || xpos > SCREEN_HEIGHT){
        xpos -= xvel;
    }

    destRect.x = int(xpos);
    destRect.y = int(ypos);
}

void Ball::render(SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, objectTexture, &srcRect, &destRect);
    SDL_RenderPresent(renderer);
}

Ball::~Ball() {
    cout << "ball destructed" << endl;
    SDL_DestroyTexture(objectTexture);
}

unsigned Ball::startside() {
    std::default_random_engine e((unsigned int)time(nullptr));
    random = e() % 2;
    return random;
}
