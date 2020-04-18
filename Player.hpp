#pragma once

#include "PlayingCard.hpp"
#include <vector>
#include <string>

struct Player {
    // Variables
    std::vector<PlayingCard> deck;
    std::string name;
    int cardsWon;

    // Constructor
    Player(std::string playerName);

    // Methods
    PlayingCard playACard();
    bool deckIsEmpty();
    void placeCardFaceDown();
    void reset();
};