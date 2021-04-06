#include <iostream>
#include <SFML/Graphics.hpp>
int main() {
    sf::RenderWindow testWindow(sf::VideoMode(1300, 600), "SFML TEST");

    sf::Event event;
    sf::Texture texture;
    texture.loadFromFile("../assets/momoko_Deck_of_52_Stylized_Playing_Cards.png");
    sf::Sprite sprite(texture, sf::IntRect(142, 0, 71, 104));

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