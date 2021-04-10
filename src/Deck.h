#ifndef DECK_H
#define DECK_H

#include<vector>
#include<string>
#include<utility>

class Deck
{
public:
	static std::vector<std::pair<int, std::string>> playableCards;
	Deck();
	~Deck();

private:
	std::vector < std::pair<int, std::string>> _cards;
};


#endif // !1

