#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// TODO: change file path to "../" if running OS other than Windows.
void cardDisplay() {
//    texture.loadFromFile("assets/momoko_Deck_of_52_Stylized_Playing_Cards.png");
//    sf::Sprite sprite(texture, sf::IntRect(142, 0, 71, 104));
}

int main() {
    sf::RenderWindow testWindow(sf::VideoMode(1300, 600),
                                "Texas Hold'em Poker",sf::Style::Close|sf::Style::Titlebar);

    sf::Event event;
    sf::Texture texture;

    // Load a sprite to display (background design)
    if (!texture.loadFromFile("../assets/poker-table-design.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    // TODO: create graphical text & UI buttons to input.
    sf::Font font;
    if (!font.loadFromFile("../assets/sansation.ttf"))
        return EXIT_FAILURE;

    // TODO: transition text to touch targets or buttons for final UI design.
    sf::Text text("Total Chip Value: $0.00 | Bet (b) | Call (c) | Raise (r) | Fold (f)", font, 50);
    text.setFillColor(sf::Color::White);

    //------------TESTING OF DECK.H BY ADRIAN ANTONIO------
    Deck tempCards;//can now change how many decks
    tempCards.shuffle();

    //----------TESTING OF GAME.H BY JAY-MARK PASCUA-------

    Game game;
    int numPlayers = 3;
    game.setup(numPlayers); // Construct Deck and Player objects

    std::cout << "PLAYER 1 HAND:" << std::endl;
    for (const auto& x : game.p1.getHand()) {
        std::cout << x.first << ", " << x.second << std::endl;
    }
    std::cout << "P1 MONEY: $" << game.p1.getMoney() << std::endl;

    std::cout << "PLAYER 2 HAND:" << std::endl;
    for (const auto& x : game.p2.getHand()) {
        std::cout << x.first << ", " << x.second << std::endl;
    }
    std::cout << "P2 MONEY: $" << game.p2.getMoney() << std::endl;

    std::cout << "\nP1 BETS $100" << std::endl;

    game.p1.playerCurrentBet = 100;
    game.p1.bet(game.p1.playerCurrentBet);
    game.setCurrentBet(game.p1.playerCurrentBet);
    game.setPot(game.p1.playerCurrentBet);
    std::cout << "P1 CURRENT BET: $" << game.p1.playerCurrentBet << std::endl;
    std::cout << "GET CURRENT BET: $" << game.getCurrentBet() << std::endl;
    std::cout << "P1 MONEY: $" << game.p1.getMoney() << std::endl;

    std::cout << "\nP2 CALLS P1 BET"<< std::endl;

    game.p2.call(game.getCurrentBet());
    std::cout << "P2 CURRENT BET: $" << game.p2.playerCurrentBet << std::endl;
    std::cout << "GET CURRENT BET: $" << game.getCurrentBet() << std::endl;
    std::cout << "P2 MONEY: $" << game.p2.getMoney() << std::endl;

    std::cout << "\nP3 RAISES $200" << std::endl;

    game.p3.raise(game, 200); // Pass in game object to get access to the round's _currentBet
    std::cout << "P3 CURRENT BET: $" << game.p3.playerCurrentBet << std::endl;
    std::cout << "GET CURRENT BET: $" << game.getCurrentBet() << std::endl;
    std::cout << "P3 MONEY: $" << game.p3.getMoney() << std::endl;

    std::cout << "\nP1 CALLS P3" << std::endl;

    game.p1.call(game.getCurrentBet());
    std::cout << "P1 CURRENT BET: $" << game.p1.playerCurrentBet << std::endl;
    std::cout << "GET CURRENT BET: $" << game.getCurrentBet() << std::endl;
    std::cout << "P1 MONEY: $" << game.p1.getMoney() << std::endl;

    std::cout << "\nP2 FOLDS:" << std::endl;

    game.p2.fold();
    if (game.p2.isFolded() == true)
        std::cout << "P2 HAS FOLDED" << std::endl;
    else
        std::cout << "P2 HAS NOT FOLDED" << std::endl;
    
    //------------------------------------------------------
     //----------TESTING OF RANKING.H BY BENJAMIN STREAM-------
    std::vector<std::pair<int, std::string>> testCHand; // test community hand
    tempCards.drawCards(testCHand, 5);
    HandAnalysis testAnalysis;
    testAnalysis.grade(game.p1.getHand(), testCHand);

    // SFML – start the event loop.
    while (testWindow.isOpen()) {
        while (testWindow.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed)
                testWindow.close();

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

        testWindow.clear();
        testWindow.draw(sprite);
        testWindow.draw(text);
        testWindow.display();

//        // Keyboard initial input (1-9) to change amount of chips.
//        // Use b/c/r/f for bet, call, raise, and fold.
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
//            // BET
//            cout << "KEYBOARD INPUT – (BET) – B key was pressed." << endl;
//        }
//
//        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
//            // CALL
//            cout << "KEYBOARD INPUT – (CALL) – C key was pressed." << endl;
//        }
//
//        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
//            // RAISE
//            cout << "KEYBOARD INPUT – (RAISE) – R key was pressed." << endl;
//        }
//
//        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
//            // FOLD
//            cout << "KEYBOARD INPUT – (FOLD) – F key was pressed." << endl;
//        }

    }
    return 0;
}