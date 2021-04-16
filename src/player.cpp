/* Jay-Mark Pascua
   Holds player definitions
*/
#include "player.h"

Player::Player() {
}

Player::~Player() {
}

void Player::dealCards(Deck& cards) {
    cards.drawCards(_playerHand, 2);
}

void Player::bet(const int& money) { // Player bets an amount of money
    // Check if player has sufficient amount of money to make a bet
    // Subtract bet from player's money
}

void Player::call(const int& money) { // Player places down same amount of money as previous player's bet
    // Check if player has sufficient amount of money to make the bet
        // Fold if not enough money
    // Subtract bet from player's money equal to the bet made by the previous player
}

void Player::raise(const int& money) { // Player bets more than what a previous player bet
    // Check if player has sufficient amount of money and is greater than the previous bet to make the raise
    // Subtract raise from player's money

}

void Player::fold() { // Player sits out for the rest of the round
    // Nullify the player's cards for the rest of the round (they are no longer taken into consideration when calculating the highest ranking hand
}

std::vector<std::pair<int, std::string>> Player::getHand() const {
    return _playerHand;
}

int Player::getMoney() const {
    return _money;
}