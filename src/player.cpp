/*
 * CS 202 Final Project (Spring 2021) Texas Hold'em Poker
 * By: Adrian Antonio, Benjamin Stream, Jay-Mark Pascua, & Solomon Himelbloom
*/

/* Jay-Mark Pascua
   Holds player definitions
*/
#include "game.h"
#include "player.h"
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


void Player::check() {
    _checked = true;
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

