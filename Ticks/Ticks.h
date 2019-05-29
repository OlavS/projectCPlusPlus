#ifndef SNAKE_TICKS_H
#define SNAKE_TICKS_H

#include <vector>
#include "../SnakeHead/SnakeHead.h"
#include "../SnakeBody/SnakeBody.h"
#include "../gameBoard/GameBoard.h"

/**
 * The Tick class, is the class for controlling the game's iterations. Initializes a start, and thereafter runs a loop
 * with repeating methods for the game.
 */
class Ticks {
private:

    /**
     * snakeHead to be placed controlled by the player, and placed on the board.
     */
    SnakeHead snakeHead;

    /**
     * The snakeBody follows the head, and grows in size per fruit eaten.
     */
    SnakeBody snakeBody;

    /**
     * The gameBoard places  the head and body in a grid, and determines how they are rendered.
     */
    GameBoard gameBoard;

    /**
     * Determines if the Ticks::Run() function's while loop runs.
     */
    bool running = true;

    /**
     * Decides how much time the user has for inputs.
     */
    int inputTime = 100;

public:
    Ticks();

    /**
     * Per "tick" a set number of methods are executed. These functions are inside this function:
     * @function render():      Is how console window shows the game, based on the data from the game objects. SnakeBody, SnakeHead
     * and GameBoard.
     * @function input_func():  Is how the game handles user_input per iteration/tick.
     * @function logig():       Is how the game computes the data, and decides on them  in regards to the game rules.
     */
    int run();

    /**
     * Lets the player input a value, in a set amount of time before the function ends.
     * The method determines the rotation of the snakeheads heading.
     * @see SnakeHead::turn_left
     * @see SnakeHead::turn_right
     * @see SnakeHead::set_heading
     * @param Time      is a user defined timeframe for the method.
     */
    int input_func(double time);

    /**
     * The logic method executes game logic on the actors, in regards to collisions and movements.
     * @return          status code 0 if everything went well.
     */
    int logic();

    /**
     * Determines what shall be rendered/drawn form the game to the console.
     * @return          status code 0 if everything went well.
     */
    int render();

     /**
     * The starting method for the Run(). Sets upp all the actors, for usage per tick.
     * @return          status code 0 if everything went well.
     */
    int initialize();

};


#endif //SNAKE_TICKS_H
