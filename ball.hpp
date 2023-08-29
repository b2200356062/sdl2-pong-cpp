
#ifndef DATAORIENT_BALL_HPP
#define DATAORIENT_BALL_HPP
#define BALL_VELOCITY 8


#include "gameobject.hpp"

class Ball : public GameObject{
public:

    Ball(float posx, float posy, const std::string& fileName);
    ~Ball();

    void update();
    void render();

private:

};

#endif //DATAORIENT_BALL_HPP
