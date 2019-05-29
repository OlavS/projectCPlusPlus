#ifndef SNAKE_GAMEBOARD_H
#define SNAKE_GAMEBOARD_H

#include <vector>
#include <random>
#include <chrono>
#include <windows.h>
#include "../SnakeBody/SnakeBody.h"
#include "../SnakeHead/SnakeHead.h"

class GameBoard {
private:
    unsigned int width;
    unsigned int height;
    int points;
    std::vector<std::vector<char>> board;

    // A long long int to contain a seed made from the current time.
    long long int seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    // Splits the long long int in two (using bitshift) for usage in a seed sequence.
    std::seed_seq seeder{uint32_t(seed), uint32_t(seed >> 32)};
    // A pseudorandom number generator. It consumes the seed sequence to not generate the same sequence
    // each time the program is run.
    std::mt19937 mt;
    // For generation of a random x coordinate
    std::uniform_int_distribution<> randX;
    // For generation of a random y coordinate
    std::uniform_int_distribution<> randY;

    HANDLE writeHandle;

    /**
     * Initializer for the gamestate 2d vector. Fills the whole 2d vector with chars to represent
     * either walls or empty space. ('W' for a wall, ' ' for an empty space.)
     *
     * @param b     The 2d vector for storage of the games state.
     */
    void initializeBoard(std::vector<std::vector<char>>* b);

    //vectors to draw from without replacement
    std::vector<int> numberPileX;
    std::vector<int> numberPileY;
    //Draw number function
    int drawNumber(int max);

    bool newFruitInRow( int rowNr);

public:

// Constructor

    /**
     * Standard contructor for the GameBoard class. It's predefined to contain a board with a
     * width of 30 units and height of 25. ( A unit is 2 chars wide and 1 line high when drawn
     * to the console).
     */
    GameBoard();
// Draw functions

    /**
     * A function for setting the cursorposition in the console while drawing the gamestate to the screen.
     */
    void setCursorPosition(int x, int y);
    /**
     * Draws the game-state to the console when called.
     * It first constructs a string og all the information stored in the 2d game-state vector, then prints
     * it to the console via cout from a cursor position of 0,0 in the console window.
     */
    void drawBoard();

    /**
     * Draws the instructions for the player over the board at the start of a game.
     */
    void drawStartMessage();

    /**
     * Draws the "Game Over" message and the accumulated number of points when the game ends.
     */
    void drawEndGameMessage();

// Setters

    /**
     * Creates a new fruit, uses a predefined random generator to randomly select an empty spot
     * through a do/while loop.
     */
    void newFruit();

    /**
     * Each time a fruit is “eaten” we generate and place a new fruit using a function that places
     * it randomly in an empty space on the gameboard. This is done using an algorithm that
     * generate random coordinates and checks if that space on the gameboard is empty, without
     * ever drawing the same coordinate pair twice.
     */
    void newFruitNoReplace();

    /**
     * Sets the contents of the supplied coordinates in the 2d game-state vector to the supplied
     * char value.
     *
     * @param x     The x coordinate
     * @param y     The y coordinate
     * @param c     The char value to be added at the coordinates.
     */
    void setContent(int x, int y, char c);

    /**
     * Uses setContent to add the SnakeHead to the game board
     * @param snakeHead     The snake's head, which has a Position which is used to hold the
     *                      coordinates of the head.
     */
    void setSnakeHead(SnakeHead * snakeHead);

    /**
     * Uses setContent to add the SnakeBody to the game board. Only the first and last element
     * is drawn, to keep the game as resource efficient as possible.
     * @param snakeBody     The snake's body, which contains a vector of positions which is
     *                      used to hold the coordinates of the head.
     */
    void setSnakeBody(SnakeBody * snakeBody);

    /**
     * Adds the value of the points param to the games point total when called. (Once each time a
     * fruit is "eaten").
     *
     * @param points    The number of points to be added.
     */
    void addPoints(int points);

// Getters
    /**
     * Returns the contents of the supplied coordinates from the 2d game-state vector.
     *
     * @param x         The x coordinate
     * @param y         The y coordinate
     * @return          The char value of the coordinate
     */
    char getContent(int x, int y);

// Destructor
    virtual ~GameBoard();
};


#endif //SNAKE_GAMEBOARD_H
