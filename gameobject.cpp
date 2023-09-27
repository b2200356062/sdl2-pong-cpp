#include "gameobject.hpp"

GameObject::GameObject() {

}

void GameObject::checkCollision(GameObject *object1) {
    isCollided = SDL_IntersectRect(&object1->destRect, &this->destRect, &resultRect);
}

void GameObject::update() {

    if(isCollided){
        xpos += xvel;

        if(ypos < 0 || ypos > SCREEN_HEIGHT){
            ypos -= yvel;
        }
        if(xpos < 0 || xpos > SCREEN_WIDTH){
            xpos -= xvel;
        }
    }
}

void GameObject::render(SDL_Renderer *renderer) {

}

GameObject::~GameObject() {
    cout << "game object cleaned" << endl;
}

