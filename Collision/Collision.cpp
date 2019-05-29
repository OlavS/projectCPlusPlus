#include <iostream>
#include <unistd.h>
#include "Collision.h"

Collision::Collision()= default;

bool Collision::collision(SnakeHead * snakeHead, SnakeBody * snakeBody, GameBoard * gameBoard) {
    
    char col = gameBoard->getContent(snakeHead->getPosition().getPosition_X(), snakeHead->getPosition().getPosition_Y());

    switch (col){

        case 'W':
            gameBoard->drawEndGameMessage();
            sleep(1);
            return true;

        case 'o':
            gameBoard->drawEndGameMessage();
            sleep(1);
            return true;

        case '*':
            gameBoard->addPoints(10);
            snakeBody->addBodyPart(snakeHead->getPrevPosition());
            gameBoard->setSnakeBody(snakeBody);
            gameBoard->newFruitNoReplace();
            break;

        default:
            snakeBody->move(snakeHead->getPrevPosition());
            gameBoard->setSnakeBody(snakeBody);
    }

    return false;
}
