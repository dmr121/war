#include "GameOfWar.hpp"
#include <iostream>
#include <iomanip>

// Constructor
GameOfWar::GameOfWar(std::string argument)
    : player1("Player 1"), player2("Player 2"), winner(NULL),
      seed(std::chrono::system_clock::now().time_since_epoch().count()) {
    if (argument == "-v") {
        verbose = true;
        std::cout << "P1     P2\n";
        std::cout << "----------\n";
    } else {
        verbose = false;
    }
    setup();
}

//Public Methods
void GameOfWar::restart() {
    player1.reset();
    player2.reset();
    setup();
    winner = NULL;
}

void GameOfWar::play() {
    while (winner == NULL) {
        int cardsOnDeck = 0;
        startRound(cardsOnDeck);
        if (player1.deckIsEmpty()) {
            determineWinner();
            break;
        }
    }

    std::cout << "\nPlayer 1 won " << player1.cardsWon << " cards vs. Player 2's " << player2.cardsWon << " cards\n";
    if (winner == NULL) {
        std::cout << "DRAW\n";
    } else {
        std::cout << "WINNER: " << winner->name << '\n';
    }
}

//Private Methods
void GameOfWar::setup() {
    // Declare a new deck and populate it with 52 cards
    std::vector<PlayingCard> deck;
    populateDeck(deck);

    // Shuffle the deck
    seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));

    // Splitting the deck between the 2 players
    int cardNumber = 0;
    for (auto itr = deck.begin(); itr < deck.end(); ++itr) {
        if (cardNumber % 2 == 0) {
            player1.deck.push_back(*itr);
        } else {
            player2.deck.push_back(*itr);
        }
        ++cardNumber;
    }
}

void GameOfWar::determineWinner() {
    if (player1.cardsWon > player2.cardsWon) {
        winner = &player1;
    } else if (player1.cardsWon < player2.cardsWon) {
        winner = &player2;
    } else {
        // This is a draw. Nothing happens.
    }
}

void GameOfWar::startRound(int &cardsOnDeck) {
    // Each player lays down a card face up
    PlayingCard player1Card = player1.playACard();
    PlayingCard player2Card = player2.playACard();
    cardsOnDeck += 2; // Add 2 cards to the deck that are up for grabs

    if (verbose) {
        std::cout << player1Card.rank;
        if (player1Card.rank < 10) {
            std::cout << "   v.  ";
        } else {
            std::cout << "  v.  ";
        }
        std::cout << player2Card.rank << " - ";
    }

    // Check which card is higher
    if (player1Card <= player2Card) {
        if (player1Card == player2Card) {
            // Always need to check if the deck is empty to avoid segmentation faults
            if (!player1.deckIsEmpty()) {
                player1.placeCardFaceDown();
                player2.placeCardFaceDown();
                cardsOnDeck += 2;
            }

            // This block only runs if there are cards still in the players'
            // decks
            if (!player1.deckIsEmpty()) {
                // Only need to check if one of the decks in empty
                // because they empty at the same rate
                if (verbose) {
                    std::cout << "Draw. Begin War!\n";
                }
                startRound(cardsOnDeck);
            } else {
                if (verbose) {
                    std::cout << "Decks empty. Game over\n";
                }
            }
        } else {
            player2.cardsWon += cardsOnDeck;
            if (verbose) {
                std::cout << "Player 2 wins " << cardsOnDeck << " cards\n";
            }
        }
    } else {
        player1.cardsWon += cardsOnDeck;
        if (verbose) {
            std::cout << "Player 1 wins " << cardsOnDeck << " cards\n";
        }
    }
}

// populateDeck modifies deck argument passed by reference
void GameOfWar::populateDeck(std::vector<PlayingCard> &deck) {
    // Adding 52 cards to the deck
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            PlayingCard card = PlayingCard(Suit(i), Rank(j));
            deck.push_back(card);
        }
    }
}