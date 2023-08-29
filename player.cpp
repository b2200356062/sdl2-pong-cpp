
#include "player.hpp"

Player::Player(float posx, float posy, const std::string& fileName) {
    objectTexture = TextureManager::loadTexture(fileName.c_str());

    this->xpos = posx;
    this->ypos = posy;

    this->yvel = 0;
    this->xvel = 0;

    SDL_QueryTexture(objectTexture, nullptr, nullptr, &width, &height);

    this->srcRect.x = 0;
    this->srcRect.y = 0;
    this->srcRect.h = height;
    this->srcRect.w = width;

    this->destRect.x = int(xpos);
    this->destRect.y = int(ypos);
    this->destRect.h = height;
    this->destRect.w = width;
}

void Player::update() {
    ypos += yvel;

    if(ypos < 5 || ypos > SCREEN_HEIGHT - height - 5){
        ypos -= yvel;
    }
    destRect.x = int(xpos);
    destRect.y = int(ypos);
}

void Player::render() {
    SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
}

Player::~Player() {
    SDL_DestroyTexture(objectTexture);
    cout << "player destructed"<< endl;
}
