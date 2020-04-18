#include "Player.hpp"

// Constructor
Player::Player(std::string playerName)
        : cardsWon(0), name(playerName), deck() {}

// Methods
PlayingCard Player::playACard() {
    PlayingCard card = deck.back();
    deck.pop_back();
    return card;
}

bool Player::deckIsEmpty() {
    return deck.empty();
}

void Player::placeCardFaceDown() {
    deck.pop_back();
}

void Player::reset() {
    deck.clear();
    cardsWon = 0;
}