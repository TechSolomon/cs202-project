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
void cardDisplayValue(std::vector<displayCard>& drawCard, std::vector<std::pair<int, std::string>>& cards) {
    for (auto it : cards) {
        if (it.first == 1) {
            if (it.second == "spade") {
                drawCard.push_back({ arithmethic(14), 0 });
            }
            else if (it.second == "club") {
                drawCard.push_back({ arithmethic(14), 104 });
            }
            else if (it.second == "heart") {
                drawCard.push_back({ arithmethic(14), 208 });
            }
            else if (it.second == "diamond") {
                drawCard.push_back({ arithmethic(14), 312 });
            }
        }
        else {
            if (it.second == "spade") {
                drawCard.push_back({ arithmethic(it.first), 0 });
            }
            else if (it.second == "club") {
                drawCard.push_back({ arithmethic(it.first), 104 });
            }
            else if (it.second == "heart") {
                drawCard.push_back({ arithmethic(it.first), 208 });
            }
            else if (it.second == "diamond") {
                drawCard.push_back({ arithmethic(it.first), 312 });
            }
        }


    }
}


displayCard::displayCard(int LorR, int TorB) {
    if (!cardMap.loadFromFile("assets/momoko_Deck_of_52_Stylized_Playing_Cards.png")) {
        std::cout << "ERROR LOADING FILE" << std::endl;
    }
    sf::IntRect data(LorR, TorB, 71, 104);
    cardSprite.setTexture(cardMap);
    cardSprite.setTextureRect(data);
}