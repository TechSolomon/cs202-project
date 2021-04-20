#include "player.h"
#include "deck.h"
#include "ranking.h"

#ifndef GAME_H
#define GAME_H

class Game
{
public:
	Player p1;
	Player p2;
	Player p3;
	Player p4;

	Game();
	~Game();

	void setup(int& players); // Constructs deck and player objects before starting the game
	void gameLoop(Game& game); // Starts a round of poker

	void setPot(const int& bet);
	int getPot(const int& bet) const;

	void setCurrentBet(const int& bet);
	int getCurrentBet() const;

	friend void Player::raise(Game& game, const int& raise);

private:
	Deck _cards;
	int _numPlayers;
	int _pot = 0; // Money earned after winning round
	int _currentBet = 0; // The round's current highest bet
};



#endif // !GAME_H
