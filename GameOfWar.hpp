#pragma once

#include "Player.hpp"
#include <string>
#include <algorithm>
#include <chrono>
#include <random>

class GameOfWar {
    private:

    // Variables
    Player player1;
    Player player2;
    Player * winner;
    unsigned seed;
    bool verbose;

    // Methods
    void populateDeck(std::vector<PlayingCard> &);
    void startRound(int &);
    void determineWinner();
    void setup();

    public:

    // Constructor
    GameOfWar(std::string);

    // Methods
    void play();
    void restart();
};