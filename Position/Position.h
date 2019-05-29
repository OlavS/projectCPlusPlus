#ifndef SNAKE_POSITION_H
#define SNAKE_POSITION_H


#include <string>

/**
 * Position is a object for referencing the objects positions on a 2d grid, and logic for moving them.
 */
class Position {
private:
    int position_X,
            position_Y,
            prev_Position_X,
            prev_Position_Y;

public:

    /**
     * Default constructor
     */
    Position();

    /**
     * Initiates a instanse of Position which is the coordinates of a point in a two dimansional context.
     * @param x     the X component of the point.
     * @param y     the Y component of the point.
     */
    Position(int x, int y);

    /**
     * Increments or decrements the Y component
     * @param val   the amount to add to the Y component
     */
    void move_X(int val);

    /**
     * Increments or decrements the X component
     * @param val   the amount to add to the X component
     */
    void move_Y(int val);

    /**
     * Increments or decrements the X and Y component
     * @param x     the amount to add to the X component
     * @param y     the amount to add to the Y component
     */
    void move(int x, int y);

    /**
     * Getter for the X component of the Position
     * @return      the X component
     */
    int getPosition_X() const;

    /**
     * Getter for the Y component of the Position
     * @return      the Y component
     */
    int getPosition_Y() const;

    /**
     * Getter for the X component of the Positions previous coordinate
     * @return      the X component of the previous position
     */
    int getPrev_Position_X() const;

    /**
     * Getter for the Y component of the Positions previous coordinate
     * @return      the Y component of the previous position
     */
    int getPrev_Position_Y() const;

    /**
     * Getter for the previous position
     * @return      the previous position
     */
    Position getPrevPosition();

    /**
     * Setter for the Position's X component
     * @param position_X    the X component
     */
    void setPosition_X(int position_X);

    /**
     * Setter for the Position's Y component
     * @param position_Y    the Y component
     */
    void setPosition_Y(int position_Y);

    /**
     * Setter for the Position's previous position
     */
    void setPreviousPosition();

    /**
     * Setter for the Position's previous position
     * @param x     the X component of the previous position
     * @param y     the Y component of the previous position
     */
    void setPreviousPosition(int x, int y);

    /**
     * Prints information about the Position
     * @return      information about the Position
     */
    std::string toString() const;
};


#endif //SNAKE_POSITION_H
