#include <iostream>
#include <thread>
#include <conio.h>
#include "Ticks/Ticks.h"
#include "gameBoard/GameBoard.h"

/**
 * Method for restart game or not.
 * @return bool for if the player decides to try again or exit the game.
 */
bool restartSelect(){
    char select = 0;

        do {
            if (kbhit() != 0) {
                select = tolower(_getch());
            }
        }while(!(select == 'y' || select == 'n'));

    return select == 'y';
}


int main() {

    //Decides that the program should run.
    bool run = true;

    while (run) {

        //Creates new Tick instance.
        auto *ticks = new Ticks();
        //Starts and runs the Tick
        ticks->run();

        //After the game is ended, the player can decide to restart or exit the application.
        run = restartSelect();
    }
    return 0;

}





