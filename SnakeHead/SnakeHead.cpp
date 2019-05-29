#include <iostream>
#include "SnakeHead.h"

SnakeHead::SnakeHead(int position_X, int position_Y, int heading) :
        heading(heading) {
    this->position.setPosition_X(position_X);
    this->position.setPosition_Y(position_Y);
    this->heading = heading;

    //Needs to define previous position, so as to let the tail have a starting reference.
    this->position.setPreviousPosition((position_Y - 1), position_X);
}

void SnakeHead::turn_Left() {
    setHeading(false);
}

void SnakeHead::turn_Right() {
    setHeading(true);
}


void SnakeHead::move() {
    position.setPreviousPosition();

    switch (heading){
        case 0 :
            position.move_Y(-1);
            break;
        case 1 :
            position.move_X(1);
            break;
        case 2 :
            position.move_Y(1);
            break;
        case 3:
            position.move_X(-1);
            break;

        default: std::cout<< "Invalid heading var" << std::endl;
    }
}

const Position &SnakeHead::getPosition() const {
    return position;
}

int SnakeHead::getPositionX() {
    return this->getPosition().getPosition_X();
}

int SnakeHead::getPositionY() {
    return this->getPosition().getPosition_Y();
}



void SnakeHead::setHeading(bool clockWise) {
    if(clockWise){
        heading ++;
    } else{
        heading--;
    }

    if(heading > 3){
        heading = 0;
    } else if(heading < 0){
        heading = 3;
    }
}

Position SnakeHead::getPrevPosition(){
    return position.getPrevPosition();
}

SnakeHead::SnakeHead() = default;

