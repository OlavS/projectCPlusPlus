#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>
#include "GameBoard.h"
#include <stdlib.h>
#include <Windows.h>
#include <algorithm>

using namespace std;

// Constructor
GameBoard::GameBoard() {
    height = 25;
    width = 30;
    points = 0;

    vector<vector<char>> b(height, vector<char>(width));
    board = b;

    mt = mt19937(seeder);
    randX = uniform_int_distribution<> (1, (width -1));
    randY = uniform_int_distribution<> (1, (height -1));

    // Initializing vectors to hold the possible coords to draw
    for ( int i = 1; i < width - 1; ++i ) {
        numberPileX.push_back(i);
    };
    for ( int i = 1; i < height - 1; ++i ) {
        numberPileY.push_back(i);
    }

    // Console writer
    // Handles
    writeHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    // Console window title
    SetConsoleTitle(TEXT("The Terminal Snake"));

/**
 *  Some set up to make sure the console works as expected, as the windows
 *  console might have different default set-ups depending on user preferences and the
 *  version of the operating system.
 *  This is needed as the buffer size and window size has a near circular dependency
 *  on each other.
 */
    // Set visual size to a minimum so ScreenBuffer can shrink below the actual visual size
    SMALL_RECT m_rectWindow = { 0, 0, 1, 1 };
    SetConsoleWindowInfo(writeHandle, TRUE, &m_rectWindow);

    // Setting a console buffer and its size
    COORD consoleBufferSize = {92, 35};
    SetConsoleScreenBufferSize(writeHandle, consoleBufferSize);

    // Assigning screenbuffer to the console
    SetConsoleActiveScreenBuffer(writeHandle);

    // Setting the condole window size that we want.
    SMALL_RECT consoleWindowSize = {0, 0, 91, 34};
    SetConsoleWindowInfo(writeHandle, TRUE, &consoleWindowSize);

    initializeBoard(&board);

};

// GameBoard initializer
void GameBoard::initializeBoard(std::vector<std::vector<char>>* b) {
    for (int i = 0; i < b->size(); ++i) {
        for (int j = 0; j < b->at(i).size(); ++j) {
            if (i == 0 || j == 0 || j == (b->at(i).size() - 1) || i == (b->size() -1)) {
                b->at(i).at(j) = 'W';
            } else {
                b->at(i).at(j) = ' ';
            }
        }
    }
}

// Draw functions
void GameBoard::setCursorPosition(int x, int y)
{
    COORD coordinate = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(writeHandle, coordinate);
}

void GameBoard::drawBoard() {
    setCursorPosition(0,0);
    std::string out =
            "\n\t\t  ==================THE TERMINAL SNAKE===================\n";
    out +=  "\n\t\t                    POINTS: " + to_string(points) + "      ";
    out +=  "\n\n\n";

    for (auto & i : board) {
        out+= "\t\t";
        for (char j : i) {
            out += j;
            out += " ";
        }
        out  += "\n";
    }
    cout<<out<<flush;
}

void GameBoard::drawStartMessage() {
    setCursorPosition(17, 13); cout << "=========================================================";
    setCursorPosition(17, 14); cout << "                                                         ";
    setCursorPosition(17, 15); cout << "             WELCOME TO THE TERMINAL SNAKE               ";
    setCursorPosition(17, 16); cout << "                                                         ";
    setCursorPosition(17, 17); cout << "                                                         ";
    setCursorPosition(17, 18); cout << "          turn left = a <- O -> turn right = d           ";
    setCursorPosition(17, 19); cout << "                           o                             ";
    setCursorPosition(17, 20); cout << "                                                         ";
    setCursorPosition(17, 21); cout << "              Turn left or right to start                ";
    setCursorPosition(17, 22); cout << "                                                         ";
    setCursorPosition(17, 23); cout << "=========================================================";
    setCursorPosition(0, 31);
}

void GameBoard::drawEndGameMessage() {
    setCursorPosition(17, 14); cout << "=========================================================";
    setCursorPosition(17, 15); cout << "                                                         ";
    setCursorPosition(17, 16); cout << "            YOU CRASHED AND KILLED THE SNAKE!            ";
    setCursorPosition(17, 17); cout << "                                                         ";
    setCursorPosition(17, 18); cout << "                   YOU GOT "
                                                                    + to_string(points)
                                                                    + " POINTS                   ";
    setCursorPosition(17, 19); cout << "                                                         ";
    setCursorPosition(17, 20); cout << "                   Try Again? ( y / n )                  ";
    setCursorPosition(17, 21); cout << "                                                         ";
    setCursorPosition(17, 22); cout << "=========================================================";
    setCursorPosition(0, 31);
}

// Different newFruit methods

void GameBoard::newFruit() {
    int x;
    int y;

    do {
        x = randX(mt);
        y = randY(mt);
    } while (getContent(x, y) != ' ');

    setContent(x, y, '*');
}

int GameBoard::drawNumber( int max ) {
    return uniform_int_distribution<int>{0, max}(mt);
}

void GameBoard::newFruitNoReplace() {
    for ( int i = height -3; i > -1; i-- ) {
        int rowToTry;
        if ( i > 0 ) {
            int randomY = drawNumber(i);
            rowToTry = numberPileY[randomY];
            swap(numberPileY[randomY], numberPileY[i]);
        } else {
            rowToTry = numberPileY[0];
        }
        if ( newFruitInRow(rowToTry) ) { break; }
    }
}

bool GameBoard::newFruitInRow(int rowNr) {
    for( int j = width - 3; j > -1; j-- ) {
        int colToTry;
        if ( j > 0 ) {
            int randomX = drawNumber(j);
            colToTry = numberPileX[randomX];
            swap( numberPileX[randomX], numberPileX[j] );
        } else {
            colToTry = numberPileX[0];
        }
        if ( getContent( colToTry, rowNr ) == ' ' ) {
            setContent( colToTry, rowNr, '*' );
            return true;
        }
    }
    return false;
}


// Setters
void GameBoard::setContent(int x, int y, char c) {
    board.at(y).at(x) = c;
}


void GameBoard::setSnakeHead(SnakeHead * snakeHead){
    this->setContent(snakeHead->getPositionX(), snakeHead->getPositionY(), 'O');

}

void GameBoard::setSnakeBody(SnakeBody * snakeBody){
    this->setContent(snakeBody->getPrevPositionX(), snakeBody->getPrevPositionY(), ' ');
    this->setContent(snakeBody->getFirstPositionX(), snakeBody->getFirstPositionY(), 'o');
}

void GameBoard::addPoints(int points) {
    this->points += points;
}


// Getters

char GameBoard::getContent(int x, int y) {
    return board[y][x];
}

// Destructor

GameBoard::~GameBoard() = default;

