
#ifndef DATAORIENT_PLAYER_HPP
#define DATAORIENT_PLAYER_HPP

#define PLAYER_VELOCITY 8

#include "gameobject.hpp"

class Player : public GameObject{
public:

    Player(float posx, float posy, const std::string& fileName);
    ~Player() override;

    void update() override;
    void render(SDL_Renderer* renderer) override;
    void scoreupdate();

private:

};

#endif //DATAORIENT_PLAYER_HPP
