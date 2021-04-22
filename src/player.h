/*
 * CS 202 Final Project (Spring 2021) Texas Hold'em Poker
 * By: Adrian Antonio, Benjamin Stream, Jay-Mark Pascua, & Solomon Himelbloom
*/

/* Jay-Mark Pascua
   Player actions and attributes
*/
#include "deck.h"
#include <vector>
#include <string>
#include <utility>
#ifndef PLAYER_H
#define PLAYER_H

class Game;

class Player {
	friend class Game;

public:
	int playerCurrentBet = 0; // The player's current bet for the round

	Player();
	~Player();

	void dealCards(Deck& cards);

	void check();
	void bet(const int& bet);
	void call(const int& call);
	void raise(Game& game, const int& raise);
	void fold();

	std::vector<std::pair<int, std::string>> getHand() const;
	int getMoney() const;
	bool isFolded() const;

//    +----------------+-------------------+
//    | Keyboard Input | Poker Chip Amount |
//    +----------------+-------------------+
//    | 1              | 1                 |
//    +----------------+-------------------+
//    | 2              | 2                 |
//    +----------------+-------------------+
//    | 3              | 5                 |
//    +----------------+-------------------+
//    | 4              | 10                |
//    +----------------+-------------------+
//    | 5              | 20                |
//    +----------------+-------------------+
//    | 6              | 25                |
//    +----------------+-------------------+
//    | 7              | 50                |
//    +----------------+-------------------+
//    | 8              | 100               |
//    +----------------+-------------------+
//    | 9              | 500               |
//    +----------------+-------------------+
//    | 0              | 1000              |
//    +----------------+-------------------+

private:
	double _score = 0; // Player's score; highest score wins
	int _money = 10000; // Amount of poker chips each player has
	bool _isFolded = false;
	bool _checked = false; // True if player decides to "check" for their turn

	std::vector<std::pair<int, std::string>> _playerHand; // Player's current cards
};

#endif // !PLAYER_H
