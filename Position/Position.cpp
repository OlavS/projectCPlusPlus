#include "Position.h"

Position::Position(int x, int y) {
    position_X = x;
    position_Y = y;
}

void Position::move_X(int val) {
    position_X += val;
}

void Position::move_Y(int val) {
    position_Y += val;
}

void Position::move(int x, int y){
    position_X = x;
    position_Y = y;
}

int Position::getPosition_X() const {
    return position_X;
}

int Position::getPosition_Y() const {
    return position_Y;
}

int Position::getPrev_Position_X() const {
    return prev_Position_X;
}

int Position::getPrev_Position_Y() const {
    return prev_Position_Y;
}

Position Position::getPrevPosition(){
    return Position(prev_Position_X, prev_Position_Y);
}

void Position::setPosition_X(int position_X) {
    this->position_X = position_X;

}

void Position::setPosition_Y(int position_Y) {
    this->position_Y = position_Y;

}
void Position::setPreviousPosition() {
    prev_Position_X = position_X;
    prev_Position_Y = position_Y;
}

void Position::setPreviousPosition(int x, int y) {
    prev_Position_X = x;
    prev_Position_Y = y;
}

std::string Position::toString() const {
    return  "Pos x: "+ std::to_string(position_X) + "Pos y: " + std::to_string(position_Y);
}

Position::Position() {}

