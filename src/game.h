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

	bool everyoneCalled(); // Advances round phase if everyone has called
	void determineWinner() const;

	friend void Player::raise(Game& game, const int& raise);

private:
	HandAnalysis _analysis;
	Deck _cards;
	std::vector<std::pair<int, std::string>> _river;
	int _numPlayers;
	int _pot = 0; // Money earned after winning round
	int _currentBet = 0; // The round's current highest bet
	int _highestScore = 0; // The highest score a player has; this player wins
	int _roundPhase = 0; // What phase the round is currently on (Phase 0: Betting, Phase 1: Deal three cards to river
						 // Phase 2: Deal one card to river, Phase 3: Determine winner) PHASES ALTERNATE BETWEEN BETTING AND DEALING CARDS TO RIVER
};



#endif // !GAME_H
