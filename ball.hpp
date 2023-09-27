
#ifndef DATAORIENT_BALL_HPP
#define DATAORIENT_BALL_HPP
#define BALL_VELOCITY 7


#include "gameobject.hpp"

class Ball : public GameObject{
public:

    Ball(float posx, float posy, const std::string& fileName);
    ~Ball() override;

    unsigned startside();
    void update() override;
    void render(SDL_Renderer *renderer) override;

private:
    unsigned random;
};

#endif //DATAORIENT_BALL_HPP
