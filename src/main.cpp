/*
 * CS 202 Final Project (Spring 2021) Texas Hold'em Poker
 * By: Adrian Antonio, Benjamin Stream, Jay-Mark Pascua, & Solomon Himelbloom
*/

#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main() {

    Deck tempCards; // Can now change how many decks.
    tempCards.shuffle();

    Game game;
    int numPlayers = 4;
    game.setup(numPlayers); // Construct Deck & Player Objects

    std::vector<std::pair<int, std::string>> testCHand; // Community Hand
    tempCards.drawCards(testCHand, 5);
    HandAnalysis testAnalysis;
    testAnalysis.grade(game.p1.getHand(), testCHand);

    // SFML sequence & monitor for input.
    game.gameLoop();

    return 0;
}