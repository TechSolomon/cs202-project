/* Jay-Mark Pascua
   Player actions and attributes
*/
#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include <utility>

class Player
{
public:
	Player();
	~Player();

	void bet();
	void call();
	void raise();
	void fold();

private:
	int _whiteChips; // Amount of poker chips player has
	int _redChips;
	int _greenChips;
	int _blueChips;
	int _blackChips;

	std::vector<std::pair<int, std::string>> _hand; // Player's current cards
};

#endif // !PLAYER_H
