#ifndef SNAKE_SNAKEHEAD_H
#define SNAKE_SNAKEHEAD_H


#include "../Position/Position.h"


/**
 * SnakeHead is the object which determines the heading and movement of the whole snake. It is also the object which
 * interacts with other objects. @see Collision.
 * It's heading is only controlled by a change of left and right, and the snake will always move forward.
 * The SnakeHead's body is determined by a @see Position object.
 *
 * @param heading Which direction the snake is facing. And thereby will move towards.
 * @param Position the head's placement on a 2d grid array.
 */
class SnakeHead {
private:
    int heading{};

    Position position;

public:

    /**
     * Default constructor
     */
    SnakeHead();

    /**
     * Constructor with determined position_X and position_Y parametres.
     * Also decides the starting heading for the SnakeHead.
     * @param position_X    the starting X coordinate of the SnakeHead
     * @param position_Y    the starting Y coordinate of the SnakeHead
     * @param heading       which direction the snake is heading when the game starts.
     */
    SnakeHead(int position_X, int position_Y, int heading);



     /**
      * Used to set the direction of which the snake head is moving
      * @param clockWise bool which says which way the heading is to turn. counterclockwise
      * if false, clockwise if true
      */
    void setHeading(bool clockWise);

    /**
     * Uses setHeading(false), lets the snake head turn left
     * @see SnakeHead::setHeading()
     */
    void turn_Left();

    /**
     * Uses setHeading(true), lets the snake head turn right.
     * @see SnakeHead::setHeading()
     */
    void turn_Right();

    /**
     * Moves the SnakeHead through a grid, to a cell right beside it's previous position.
     * The movement is determined by the heading of the SnakeHead.
     */
    void move();


    /**
     * Getter for the X coordinate of the SnakeHead.
     * @return      Position's X coordinate
     */
    int getPositionX();

    /**
     * Getter for the Y coordinate of the SnakeHead.
     * @return      Position's Y coordinate
     */
    int getPositionY();

    /**
     * Getter for the Position object which contains the SnakeHead
     * @return      The Position object which contains the coordinates of the SnakeHead and its
     *              previous coordinates
     */
    const Position &getPosition() const;

    /**
     * Getter for the previous position of the SnakeHead.
     * @return      The previous position object of the SnakeHead.
     */
    Position getPrevPosition();

};


#endif //SNAKE_SNAKEHEAD_H
