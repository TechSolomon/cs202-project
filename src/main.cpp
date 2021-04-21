#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// TODO: Change file path to "../" if running OS other than Windows.
void initialization() {

    Player p;
    Game g;

    sf::RenderWindow userWindowDisplay(sf::VideoMode(1300, 600),
                                       "Test Window", sf::Style::Close | sf::Style::Titlebar);

    sf::Event event;
    sf::Texture texture;

    if (!texture.loadFromFile("../assets/poker-table-design.png")) {
        throw EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    sf::Font font;
    if (!font.loadFromFile("../assets/sansation.ttf")) {
        throw EXIT_FAILURE;
    }

    sf::Text playerCommands("Check (space) | Bet (b) | Call (c) | Raise (r) | Fold (f)", font, 50);
    playerCommands.setFillColor(sf::Color::White);
    playerCommands.move(100.f, 0.f);

    sf::Text chipAmount("Total Chip Value: $0", font, 50);
    chipAmount.setFillColor(sf::Color::White);
    chipAmount.move(50.f, 500.f);

    // SFML – start the event loop.
    while (userWindowDisplay.isOpen()) {
        while (userWindowDisplay.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed)
                userWindowDisplay.close();

            switch (event.type) {
                // TODO: Exception handling for numeric chip additions (1-9) & error checking for other keys.
                case sf::Event::KeyReleased:
                    if (event.key.code == sf::Keyboard::Enter) {
                        cout << "Enter key pressed!" << endl;
                    }
                    else if (event.key.code == sf::Keyboard::Num1) {
                        cout << "DOLLAR AMOUNT ENTERED: $1" << endl;
                    }
                    else if (event.key.code == sf::Keyboard::Num2) {
                        cout << "DOLLAR AMOUNT ENTERED: $2" << endl;
                    }
                    else if (event.key.code == sf::Keyboard::Num3) {
                        cout << "DOLLAR AMOUNT ENTERED: $3" << endl;
                    }
                    else if (event.key.code == sf::Keyboard::Num4) {
                        cout << "DOLLAR AMOUNT ENTERED: $4" << endl;
                    }
                    else if (event.key.code == sf::Keyboard::Num5) {
                        cout << "DOLLAR AMOUNT ENTERED: $5" << endl;
                    }
                    else if (event.key.code == sf::Keyboard::Num6) {
                        cout << "DOLLAR AMOUNT ENTERED: $6" << endl;
                    }
                    else if (event.key.code == sf::Keyboard::Num7) {
                        cout << "DOLLAR AMOUNT ENTERED: $7" << endl;
                    }
                    else if (event.key.code == sf::Keyboard::Num8) {
                        cout << "DOLLAR AMOUNT ENTERED: $8" << endl;
                    }
                    else if (event.key.code == sf::Keyboard::Num9) {
                        cout << "DOLLAR AMOUNT ENTERED: $9" << endl;
                    }
                    else if (event.key.code == sf::Keyboard::Num0) {
                        cout << "DOLLAR AMOUNT ENTERED: $0" << endl;
                    }
                case sf::Event::Closed:
                    break;
                case sf::Event::Resized:
                    break;
                case sf::Event::LostFocus:
                    break;
                case sf::Event::GainedFocus:
                    break;
                case sf::Event::TextEntered:
                    break;
                case sf::Event::KeyPressed:
                    break;
                case sf::Event::MouseWheelMoved:
                    break;
                case sf::Event::MouseWheelScrolled:
                    break;
                case sf::Event::MouseButtonPressed:
                    break;
                case sf::Event::MouseButtonReleased:
                    break;
                case sf::Event::MouseMoved:
                    break;
                case sf::Event::MouseEntered:
                    break;
                case sf::Event::MouseLeft:
                    break;
                case sf::Event::JoystickButtonPressed:
                    break;
                case sf::Event::JoystickButtonReleased:
                    break;
                case sf::Event::JoystickMoved:
                    break;
                case sf::Event::JoystickConnected:
                    break;
                case sf::Event::JoystickDisconnected:
                    break;
                case sf::Event::TouchBegan:
                    break;
                case sf::Event::TouchMoved:
                    break;
                case sf::Event::TouchEnded:
                    break;
                case sf::Event::SensorChanged:
                    break;
                case sf::Event::Count:
                    break;
            }
        }

        userWindowDisplay.clear();
        userWindowDisplay.draw(sprite);
        userWindowDisplay.draw(chipAmount);
        userWindowDisplay.draw(playerCommands);
        userWindowDisplay.display();

    }

}

int main() {

    //------------TESTING OF DECK.H BY ADRIAN ANTONIO------
    Deck tempCards;//can now change how many decks
    tempCards.shuffle();

    //----------TESTING OF GAME.H BY JAY-MARK PASCUA-------

    Game game;
    int numPlayers = 3;
    game.setup(numPlayers); // Construct Deck and Player objects

    //------------------------------------------------------
     //----------TESTING OF RANKING.H BY BENJAMIN STREAM-------
    std::vector<std::pair<int, std::string>> testCHand; // test community hand
    tempCards.drawCards(testCHand, 5);
    HandAnalysis testAnalysis;
    testAnalysis.grade(game.p1.getHand(), testCHand);

    // SFML sequence & monitor for input
    initialization();

    return 0;
}