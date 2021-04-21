/* Jay-Mark Pascua
   Holds player definitions
*/
#include "game.h"
#include "player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

Player::Player() {
}

Player::~Player() {
}

void Player::dealCards(Deck& cards) {
    cards.drawCards(_playerHand, 2);
}

void Player::bet(const int& bet) { // Player bets an amount of money
    // Check if player has sufficient amount of money to make a bet
    // Subtract bet from player's money
    if (_money >= bet) {
        _money -= bet;
        playerCurrentBet = bet;
    }
}

void Player::call(const int& call) { // Player places down same amount of money as previous player's bet
    // Check if player has sufficient amount of money to make the bet
        // Fold or all-in if not enough money
    // Subtract bet from player's money equal to the bet made by the previous player
    if (_money >= call) {
        _money -= call - playerCurrentBet;
        playerCurrentBet = call;
    }
}

void Player::raise(Game& game, const int& raise) { // Player bets more than what a previous player bet
    // Check if player has sufficient amount of money and is greater than the previous bet by at least $5 to make the raise
    // Subtract raise from player's money
    if (_money >= raise && raise >= game._currentBet + 5) {
        _money -= raise - playerCurrentBet;
        playerCurrentBet = raise;
        game._currentBet = raise;
    }
}

void Player::fold() { // Player sits out for the rest of the round
    // Nullify the player's cards for the rest of the round (they are no longer taken into consideration when calculating the highest ranking hand
    _playerHand.erase(_playerHand.begin(), _playerHand.end());
    _isFolded = true;
}

std::vector<std::pair<int, std::string>> Player::getHand() const {
    return _playerHand;
}

int Player::getMoney() const {
    return _money;
}

bool Player::isFolded() const {
    return _isFolded;
}

// TODO: Change file path to "../" if running OS other than Windows.
void Player::events() {

    sf::RenderWindow testWindow(sf::VideoMode(1300, 600),
                                "Test Window",sf::Style::Close|sf::Style::Titlebar);

    sf::Event event;
    sf::Texture texture;

    if (!texture.loadFromFile("assets/poker-table-design.png")) {
        throw EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/sansation.ttf")) {
        throw EXIT_FAILURE;
    }

    sf::Text playerCommands("Check (space) | Bet (b) | Call (c) | Raise (r) | Fold (f)", font, 50);
    playerCommands.setFillColor(sf::Color::White);
    playerCommands.move(100.f, 0.f);

    sf::Text chipAmount("Total Chip Value: $0", font, 50);
    chipAmount.setFillColor(sf::Color::White);
    chipAmount.move(50.f, 500.f);

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

}

void Player::getPlayerInput(Game& game, Player& p) const {
    while (true) { // Wait for input then break when found
        int bet; // Player's inputed amount of money

        // Keyboard initial input (1-9) to change amount of chips.
        // Use b/c/r/f for bet, call, raise, and fold.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { // Player checks (moves on to next player's turn)
            sf::sleep((sf::milliseconds(150)));
            std::cout << "KEYBOARD CHECK (CHECK). Space key was pressed." << std::endl;
            break;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
            // BET
            sf::sleep((sf::milliseconds(150)));
            std::cout << "KEYBOARD INPUT (BET). B key was pressed." << std::endl;
            std::cin >> bet;
            p.bet(bet);
            game.setCurrentBet(p.playerCurrentBet);
            game.setPot(p.playerCurrentBet);
            std::cin.clear();
            break;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
            // CALL
            sf::sleep((sf::milliseconds(150)));
            std::cout << "KEYBOARD INPUT (CALL). C key was pressed." << std::endl;
            p.call(game.getCurrentBet());
            game.setCurrentBet(p.playerCurrentBet);
            game.setPot(p.playerCurrentBet);
            std::cin.clear();
            break;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            // RAISE
            sf::sleep((sf::milliseconds(150)));
            std::cout << "KEYBOARD INPUT (RAISE). R key was pressed." << std::endl;
            std::cin >> bet;
            p.raise(game, bet);
            game.setCurrentBet(p.playerCurrentBet);
            game.setPot(p.playerCurrentBet);
            std::cin.clear();
            break;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            // FOLD
            sf::sleep((sf::milliseconds(150)));
            std::cout << "KEYBOARD INPUT (FOLD). F key was pressed." << std::endl;
            std::cin.clear();
            break;
        }
    }

    // TODO: Exception handling for numeric chip additions (1-9) & error checking for other keys.
}