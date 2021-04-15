#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "deck.h"
int main() {
    sf::RenderWindow testWindow(sf::VideoMode(1300, 600), "SFML");

    sf::Event event;
    sf::Texture texture;
    texture.loadFromFile("assets/momoko_Deck_of_52_Stylized_Playing_Cards.png");
    sf::Sprite sprite(texture, sf::IntRect(142, 0, 71, 104));


    //------------TESTING OF DECK.H BY ADRIAN ANTONIO------
    Deck tempCards(4);//can now change how many decks
    for (auto i : Deck::playableCards) {
        std::cout << i.first << " " << i.second << std::endl;//just prints what's inside
    }
    std::cout << "_Test 2_" << std::endl;
    tempCards.shuffle();// shuffles the deck with amount of cards
    for (auto i : Deck::playableCards) {
        std::cout << i.first << " " << i.second << std::endl;// Print with changes
    }
    std::cout << "_Test 3_" << std::endl;
    std::vector<std::pair<int, std::string>> testHand;
    tempCards.drawCards(testHand, 2);
    for (auto i : testHand) {
        std::cout << i.first << " " << i.second << std::endl;// Prints test hand
    }
    std::cout << "-insideplayable-" << std::endl;
    for (auto i : Deck::playableCards) {
        std::cout << i.first << " " << i.second << std::endl;// Print with changes
    }
    //------------------------------------------------------

    //----------TESTING OF PLAYER.H BY JAY-MARK PASCUA------
    Player player(tempCards);

    std::cout << "\n\n\n\nPLAYER HAND:" << std::endl;
    for (const auto& x : player.getHand()) {
        std::cout << x.first << ", " << x.second << std::endl;
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