/*
 * CS 202 Final Project (Spring 2021) Texas Hold'em Poker
 * By: Adrian Antonio, Benjamin Stream, Jay-Mark Pascua, & Solomon Himelbloom
*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main() {
    sf::Music music;
    if (!music.openFromFile("assets/higherLOVE.flac"))
        return -1; // error
    music.setVolume(10.f);
    music.play();
    Game game;
    int numPlayers = 4;
    game.setup(numPlayers); // Construct Deck & Player Objects

    // SFML sequence & monitor for input.
    game.gameLoop();

    return 0;
}