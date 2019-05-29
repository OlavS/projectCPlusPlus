#ifndef SNAKE_COLLISION_H
#define SNAKE_COLLISION_H


#include "../SnakeHead/SnakeHead.h"
#include "../SnakeBody/SnakeBody.h"
#include "../gameBoard/GameBoard.h"

/**
 * Handles collisions and the logic that happends when a collision occures.
 * @see Collision
 */
class Collision {

public:

    /**
    * Default constructor
    */
    Collision();

    /**
    * If the snake hits the wall or the wall, the game will send a message to the user, and return
    * true. If the snake hits a berry 10 points will be added to the points variable in the
    * GameBoard, a body part will be added to the SnakeBody and a new apple will be added
    * to the GameBoard.
    * @param snakeHead      a pointer to the game sessions SnakeHead.
    * @param snakeBody      a pointer to the game sessions SnakeBody.
    * @param gameBoard      a pointer to the game sessions GameBoard.
    * @return               true if the SnakeHead hits the wall or the SnakeBody, else false.
    */
    static bool collision(SnakeHead* snakeHead, SnakeBody * snakeBody, GameBoard * gameBoard);

};


#endif //SNAKE_COLLISION_H
