#include "player.h"
#include "deck.h"
#include "ranking.h"

#ifndef GAME_H
#define GAME_H

class Game
{
public:
	Game();
	~Game();

	void setup(); // Constructs deck and player objects before starting the game
	void gameLoop(); // Starts a round of poker

private:
	int _pot = 0; // Money earned after winning round
	int _currentBet = 0; // The round's current highest bet
};



#endif // !GAME_H
