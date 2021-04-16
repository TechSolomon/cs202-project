/* Jay-Mark Pascua
   Player actions and attributes
*/
#include "deck.h"

#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include <utility>

class Player
{
	friend class Game;

public:
	int playerCurrentBet = 0; // The player's current bet for the round

	Player();
	~Player();

	void dealCards(Deck& cards);

	void bet(const int& bet);
	void call(const int& call);
	void raise(const int& currentBet, const int& raise);
	void fold();

	std::vector<std::pair<int, std::string>> getHand() const;
	int getMoney() const;

private:
	int _money = 1000; // Amount of poker chips player has

	std::vector<std::pair<int, std::string>> _playerHand; // Player's current cards
};

#endif // !PLAYER_H
