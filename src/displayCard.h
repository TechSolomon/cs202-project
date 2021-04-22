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
    friend void cardDisplayValue(std::vector<displayCard>& putCards, std::vector<std::pair<int, std::string>>& cards);//Do this first
    friend void offsetPosition(std::vector<displayCard>& cardPool,float y);//Moves cards to the right by 50*wherever it is in the vector
    friend void initialPosition(std::vector<displayCard>& cardPool, float x, float y);
    friend void screenCards(std::vector<displayCard>& cardPool,sf::RenderWindow &display);//Draws on a RenderedWindow
    friend void initialWithOffsetPostion(std::vector<displayCard>& cards, float x, float y);//does both initial and offset
public:
    displayCard(int LorR, int UorB);
    sf::Sprite cardSprite;
private:
};




#endif //DISPLAYCARD_H

