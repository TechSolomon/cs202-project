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
    friend void cardDisplayValue(std::vector<displayCard>& drawCard, std::vector<std::pair<int, std::string>>& cards);
    friend void OffsetPosition(std::vector<displayCard>& cardPool);
    friend void initialPoisition(std::vector<displayCard>& cardPool);
public:
    displayCard(int LorR, int UorB);
    sf::Sprite cardSprite;
private:
};




#endif //DISPLAYCARD_H

