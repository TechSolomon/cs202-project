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

	void bet(const int& money);
	void call(const int& money);
	void raise(const int& money);
	void fold();

private:
	int _money = 1000; // Amount of poker chips player has

	std::vector<std::pair<int, std::string>> _hand; // Player's current cards
};

#endif // !PLAYER_H
