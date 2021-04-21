#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main() {

    //------------TESTING OF DECK.H BY ADRIAN ANTONIO------
    Deck tempCards;//can now change how many decks
    tempCards.shuffle();

    //----------TESTING OF GAME.H BY JAY-MARK PASCUA-------

    Game game;
    int numPlayers = 4;
    game.setup(numPlayers); // Construct Deck and Player objects

    //------------------------------------------------------
     //----------TESTING OF RANKING.H BY BENJAMIN STREAM-------
    std::vector<std::pair<int, std::string>> testCHand; // test community hand
    tempCards.drawCards(testCHand, 5);
    HandAnalysis testAnalysis;
    testAnalysis.grade(game.p1.getHand(), testCHand);

    // SFML sequence & monitor for input
    game.gameLoop();

    return 0;
}