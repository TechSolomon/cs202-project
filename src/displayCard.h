//
// Created by Adrian Antonio on 4/20/2021.
//

#ifndef DISPLAYCARD_H
#define DISPLAYCARD_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>




static sf::Texture cardMap;
class displayCard {
    friend void cardDisplayValue(std::vector<displayCard>& putCards, std::vector<std::pair<int, std::string>>& cards);
    friend void OffsetPosition(std::vector<displayCard>& cardPool);//Moves cards to the right by 50*wherever it is in the vector
    friend void initialPoisition(std::vector<displayCard>& cardPool, float x, float y);
    friend void screenCards(std::vector<displayCard>& cardPool,sf::RenderWindow &display);//Draws on a RenderedWindow
public:
    displayCard(int LorR, int UorB);
    sf::Sprite cardSprite;
private:
};




#endif //DISPLAYCARD_H

