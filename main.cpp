#include "GameOfWar.hpp"

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char * argv[]) {
    std::cout << "WELCOME TO THE GAME OF WAR\n";
    std::cout << "The following program simulates a game between 2 players, each dealt random decks.\n";
    std::cout << "Press any key to play a game.";
    std::cin.ignore();

    // Starts out as an empty argument before we know if the user provides one
    std::string argument = "";
    // Checking to see if the user gave an argument in the command line
    if (argc > 1) {
        // Only argument acceptable is '-v'
        argument = argv[1];
        if (argument == "-v") {
            argument = "-v";
        }
    }

    GameOfWar game = GameOfWar(argument);
    bool keepPlaying = true;

    while(keepPlaying) {
        game.play();

        std::cout << "\nKeep playing?\n";
        std::cout << "Any key to play again. [n] to exit: ";

        if (std::cin.get() == 'n') {
            keepPlaying = false;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            game.restart();
        }
    }

    return 0;
}