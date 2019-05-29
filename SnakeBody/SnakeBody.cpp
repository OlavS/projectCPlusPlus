#include "SnakeBody.h"

SnakeBody::SnakeBody(int length, Position position){
    position.setPosition_Y(position.getPosition_Y() - 1);
    position.setPreviousPosition(position.getPosition_X(), position.getPosition_Y() - 1);
    this->body.insert(body.begin(), position);
    for(int i = 1; i < length; i++){
        position.setPosition_Y(position.getPosition_Y() - 1);
        position.setPreviousPosition(position.getPosition_X(), position.getPosition_Y() - 1);
        this->body.insert(body.end(), position);
    }
}

void SnakeBody::addBodyPart(Position position) {
    position.setPreviousPosition(body[1].getPosition_X(), body[1].getPosition_Y());
    this->body.insert(body.begin(), position);
}

void SnakeBody::move(Position position) {
    body.pop_back();
    position.setPreviousPosition(body[1].getPosition_X(), body[1].getPosition_Y());
    body.insert(body.begin(), position);
}

void SnakeBody::resetBody(int length, Position position) {
    this->body.erase(body.begin(), body.end());
    SnakeBody(length, position);
}

Position SnakeBody::getPrevPosition(){
    return body.back().getPrevPosition();
}

int SnakeBody::getPrevPositionX() {
    return getPrevPosition().getPosition_X();
}

int SnakeBody::getPrevPositionY() {
    return getPrevPosition().getPosition_Y();
}

int SnakeBody::getFirstPositionX(){
    return getBody().front().getPosition_X();
}

int SnakeBody::getFirstPositionY(){
    return getBody().front().getPosition_Y();
}

int SnakeBody::getSize() const {
    return body.size();
}

std::vector<Position> SnakeBody::getBody() {
    return body;
}

SnakeBody::SnakeBody() = default;


