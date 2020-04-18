#pragma once

enum Rank {
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace,
};

enum Suit {
    heart,
    diamond,
    spade,
    club,
};

struct PlayingCard {

    // Variables
    Rank rank;
    Suit suit;

    // Constructor
    PlayingCard(Suit suit, Rank rank);

    // Overloaded Operator Methods
    bool operator <= (PlayingCard otherCard);
    bool operator == (PlayingCard otherCard);
};