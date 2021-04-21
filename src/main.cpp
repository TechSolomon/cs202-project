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
    if (!texture.loadFromFile("assets/poker-table-design.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    // TODO: create graphical text & UI buttons to input.
    sf::Font font;
    if (!font.loadFromFile("assets/sansation.ttf"))
        return EXIT_FAILURE;

    // TODO: transition text to touch targets or buttons for final UI design.
    sf::Text playerCommands("Check (space) | Bet (b) | Call (c) | Raise (r) | Fold (f)", font, 50);
    playerCommands.setFillColor(sf::Color::White);
    playerCommands.move(100.f, 0.f);

    sf::Text chipAmount("Total Chip Value: $0", font, 50);
    chipAmount.setFillColor(sf::Color::White);
    chipAmount.move(50.f, 500.f);

    //------------TESTING OF DECK.H BY ADRIAN ANTONIO------
    Deck tempCards;//can now change how many decks
    tempCards.shuffle();

    //----------TESTING OF GAME.H BY JAY-MARK PASCUA-------

    Game game;
    int numPlayers = 4;
    game.setup(numPlayers); // Construct Deck and Player objects

    // game.gameLoop(game);
    
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
        }
        testWindow.clear();
        testWindow.draw(sprite);
        testWindow.draw(chipAmount);
        testWindow.draw(playerCommands);
        testWindow.display();

        
    }
    return 0;
}