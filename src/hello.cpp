#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "Deck.h"
int main() {
    sf::RenderWindow testWindow(sf::VideoMode(1300, 600), "SFML");

    sf::Event event;
    sf::Texture texture;
    texture.loadFromFile("assets/momoko_Deck_of_52_Stylized_Playing_Cards.png");
    sf::Sprite sprite(texture, sf::IntRect(142, 0, 71, 104));


    //------------TESTING OF DECK.H BY ADRIAN ANTONIO------
    Deck tempCards;
    for (auto i : Deck::playableCards) {
        std::cout << i.first << " " << i.second << std::endl;//just prints what's inside
    }
    Deck::playableCards.push_back({ 5,"test" });//manipulate the playableCards
    for (auto i : Deck::playableCards) {
        std::cout << i.first << " " << i.second << std::endl;// Print with changes
    }
    //------------------------------------------------------

    while (testWindow.isOpen()) {
        while (testWindow.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed)
                testWindow.close();
        }
        testWindow.clear();
        testWindow.draw(sprite);
        testWindow.display();
    }
    return 0;
}