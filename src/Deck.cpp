#include "Deck.h"


Deck::Deck()
{
	resetCard();
	playableCards = _cards; 
}

Deck::Deck(int amount)
{	
	resetCard();
	//Adds any amount of cards into a playableDeck
	while (amount != 0) {
		std::copy(_cards.begin(), _cards.end(), std::back_inserter(playableCards));
		amount--;
	}
	
}

Deck::~Deck()
{
}

void Deck::resetCard()
{
	_cards = {
			{1,"spade"},{2,"spade"}, {3,"spade"},{4,"spade"}, {5,"spade"},
				{6,"spade"}, {7,"spade"}, {8,"spade"}, {9,"spade"}, {10,"spade"},
					{11,"spade"}, {12,"spade"}, {13,"spade"},
			{1,"club"},{2,"club"}, {3,"club"},{4,"club"}, {5,"club"},
				{6,"club"}, {7,"club"}, {8,"club"}, {9,"club"}, {10,"club"},
					{11,"club"}, {12,"club"}, {13,"club"},
			{1,"heart"},{2,"heart"}, {3,"heart"},{4,"heart"}, {5,"heart"},
				{6,"heart"}, {7,"heart"}, {8,"heart"}, {9,"heart"}, {10,"heart"},
					{11,"heart"}, {12,"heart"}, {13,"heart"},
			{1,"diamond"},{2,"diamond"}, {3,"diamond"},{4,"diamond"}, {5,"diamond"},
				{6,"diamond"}, {7,"diamond"}, {8,"diamond"}, {9,"diamond"}, {10,"diamond"},
					{11,"diamond"}, {12,"diamond"}, {13,"diamond"}
	};	
	
}

std::vector<std::pair<int, std::string>> Deck::playableCards{};//initializing outside the class