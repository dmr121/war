#include "PlayingCard.hpp"

// Constructor
    PlayingCard::PlayingCard(Suit suit, Rank rank) {
        this->suit = suit;
        this->rank = rank;
    }

    // Methods
    bool PlayingCard::operator <= (PlayingCard otherCard) {
        return this->rank <= otherCard.rank;
    }

    bool PlayingCard::operator == (PlayingCard otherCard) {
        return this->rank == otherCard.rank;
    }