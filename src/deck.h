#ifndef DECK_H
#define DECK_H

#include<vector>
#include<string>
#include<utility>
#include<iterator>
#include<random>

class Deck
{
public:
	static std::vector<std::pair<int, std::string>> playableCards;//Manipulate this one 
	Deck();
	Deck(int amount);
	~Deck();
	void resetCard();// Makes a 1 deck with 52 cards
	void shuffle();//shuffle the playable cards
	void drawCards(std::vector<int, std::string>& v,int amount); //draws and puts it into hand or board
private:
	std::vector < std::pair<int, std::string>> _cards;
};


#endif // !1
