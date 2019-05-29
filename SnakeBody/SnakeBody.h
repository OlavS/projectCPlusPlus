#ifndef SNAKE_SNAKEBODY_H
#define SNAKE_SNAKEBODY_H

#include <vector>
#include "../Position/Position.h"

/**
 * SnakeBody is part of the complete snake which is drawn to a gameboard with a SnakeHead attached to it.
 * In summary the SnakeBody has all the required functionality needed to move it after a snakehead around a gameboard
 * and it also has functionality for adding greater length to it.
 * @see SnakeHead
 * @see GameBoard
 */
class SnakeBody {
    private:
        std::vector<Position> body;

    public:

        /**
        * Default constructor
        */
        SnakeBody();

        /**
        * Initiate a instance of SnakeBody. Constructs the body upwards (y--).
        * @param length     of the snake
        * @param position   starting point of the tail.
        */
        SnakeBody(int length, Position position);

        /**
        * Ads Position to begining of the snakebody. Sets previous position to the first element of the SnakeBody
        * @param position   a object of type Position which contains positions of the new first element of the SnakeBody.
        * @see Position
        */
        void addBodyPart(Position position);

        /**
        * Allows the SnakeBody to move by removing the last element of it and insert a new where the first element of the
        * SnakeBody is.
        * @param position   a object of type Position which contains positions of the new first element of the SnakeBody.
        * @see Position
        */
        void move(Position position);

        /**
        * Used to reset the SnakeBody to a preferable length, position where position is the first element of the SnakeBody
        * @param length     the initial length of the SnakeBody
        * @param position   the first position of the SnakeBody
        */
        void resetBody(int length, Position position);

        /**
        * Used to get the previous position of the SnakeBody.
        * @return           the previous position of the last element of the SnakeBody
        */
        Position getPrevPosition();

        /**
        * Used to get the previous position's X coordinate.
        * @return           the X coordinate of the previous position
        * @see getPrevPosition()
        */
        int getPrevPositionX();

        /**
        * Used to get the previous position's Y coordinate.
        * @return           the Y coordinate of the previous position
        * @see getPrevPosition()
        */
        int getPrevPositionY();

        /**
        * Used to get the first position's X coordinate.
        * @return           the X coordinate of the first position
        */
        int getFirstPositionX();

        /**
        * Used to get the first position's Y coordinate.
        * @return           the Y coordinate of the first position
        */
        int getFirstPositionY();

        /**
        * Getter for the size of the SnakeBody.
        * @return           the size of the SnakeBody
        */
        int getSize() const;

        /**
        * Used to get the snakes body.
        * @return           the SnakeBody which is a vector of Position
        * @see Position
        * @see std::Vector
        */
        std::vector<Position> getBody();
};


#endif //SNAKE_SNAKEBODY_H
