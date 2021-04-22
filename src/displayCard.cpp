/*
 * CS 202 Final Project (Spring 2021) Texas Hold'em Poker
 * By: Adrian Antonio, Benjamin Stream, Jay-Mark Pascua, & Solomon Himelbloom
*/

//
// Created by Adrian Antonio on 4/20/2021.
//

#include "displayCard.h"

int arithmethic(int num) {
    double d = 71.4;
    num = num - 2;
    num *= d;
    return num;
}
void cardDisplayValue(std::vector<displayCard>& putCards, std::vector<std::pair<int, std::string>>& cards) {
    for (auto it : cards) {
        if (it.first == 1) {
            if (it.second == "spade") {
                putCards.push_back({ arithmethic(14), 0 });
            }
            else if (it.second == "club") {
                putCards.push_back({ arithmethic(14), 104 });
            }
            else if (it.second == "heart") {
                putCards.push_back({ arithmethic(14), 208 });
            }
            else if (it.second == "diamond") {
                putCards.push_back({ arithmethic(14), 312 });
            }
        }
        else {
            if (it.second == "spade") {
                putCards.push_back({ arithmethic(it.first), 0 });
            }
            else if (it.second == "club") {
                putCards.push_back({ arithmethic(it.first), 104 });
            }
            else if (it.second == "heart") {
                putCards.push_back({ arithmethic(it.first), 208 });
            }
            else if (it.second == "diamond") {
                putCards.push_back({ arithmethic(it.first), 312 });
            }
        }


    }
}

void offsetPosition(std::vector<displayCard>& cardPool,float y)
{
    for (int i = 0; i < cardPool.size(); ++i) {
        cardPool[i].cardSprite.move(sf::Vector2f(i * 80.0f, y));
    }
}

void initialPosition(std::vector<displayCard>& cardPool,float x,float y)
{
    for (auto &it : cardPool) {
        it.cardSprite.setPosition(x, y);
    }
}

void screenCards(std::vector<displayCard>& cardPool, sf::RenderWindow& display)
{
    for (auto& i : cardPool) {
        display.draw(i.cardSprite);
    }
}

void initialWithOffsetPostion(std::vector<displayCard>& cards, float x, float y)
{
    void initialPoisition(std::vector<displayCard>&cardPool, float x, float y);
    void OffsetPosition(std::vector<displayCard>&cardPool, float y);
}


displayCard::displayCard(int LorR, int TorB) {
    if (!cardMap.loadFromFile("assets/momoko_Deck_of_52_Stylized_Playing_Cards.png")) {
        std::cout << "ERROR LOADING FILE" << std::endl;
    }
    sf::IntRect data(LorR, TorB, 71, 104);
    cardSprite.setTexture(cardMap);
    cardSprite.setTextureRect(data);
}