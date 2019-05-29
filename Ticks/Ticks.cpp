#include <iostream>
#include <conio.h>
#include <chrono>
#include "Ticks.h"
#include "../Collision/Collision.h"



using std::cin;
using std::string;
using std::endl;

using namespace std::chrono;


/**
 * @def for easier input handling. a = Left, d = Right
 */
#define Left 97 // a
#define Right 100 // d

Ticks::Ticks() {
    snakeHead = SnakeHead(14, 12, 0);
    snakeBody = SnakeBody(3, snakeHead.getPosition());
}

int Ticks::run() {

    initialize();

    while (running) {
        render();
        input_func(inputTime);
        logic();
    }
    return 0;
}


int Ticks::input_func(double time) {

    high_resolution_clock::time_point now = high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff(time);

    /**
    * Sets a future time where the method ends.
    */
    auto max = now + diff;
    int val;

    //This is so that the first input is the only one that is valid.
    bool run = true;

    /**
     * Counts down a timeframe for how long the while loop is used.
     * In essence decides how long a user has for inputs per frame.
     */
    while( high_resolution_clock::now() < max ) {
        if (run) {

            //Listens for any keyboard input.
            if (kbhit() != 0) {

                //Sets the input to a char val.
                val = tolower(_getch());
                switch (val) {

                    case Left:
                        snakeHead.turn_Left();
                        run = false;
                        break;

                    case Right:
                        snakeHead.turn_Right();
                        run = false;
                        break;

                    default:
                        break;
                }
            }
        }
    }
    return 0;
}


int Ticks::initialize(){
    gameBoard.drawBoard();
    gameBoard.drawStartMessage();
    gameBoard.setSnakeHead(&snakeHead);
    gameBoard.newFruit();


    bool start = false;

    do {
        if (kbhit() != 0) {

            //Sets the input to a char val.
            int val = tolower(_getch());

            if (val == Left) {
                snakeHead.turn_Left();
                start = true;
            } else if (val == Right) {
                snakeHead.turn_Right();
                start = true;
            }
        }
    }while(!start);

    logic();
    return 0;
}

/**
 * Determines how the Head moves, then computes the effect of this through the collision method.
 * @return
 */
int Ticks::logic() {
    snakeHead.move();

    //If the snake collides in a wall or itself, it returns true. Then the stacks fall back to main.
    if (Collision::collision(&snakeHead, &snakeBody, &gameBoard)) {
        gameBoard.setCursorPosition(0, 0);
        running = false;
    }

    gameBoard.setSnakeHead(&snakeHead);
    return 0;
}


int Ticks::render(){
    gameBoard.drawBoard();
    return 0;
}

