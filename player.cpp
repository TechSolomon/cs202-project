/* Jay-Mark Pascua
   Holds player definitions
*/
#include "player.h"

Player::Player() {
    // Assign cards and poker chips
}

Player::~Player() {
}

void Player::bet() { // Player bets an amount of chips
    // Check if player has sufficient amount of chips to make a bet
    // Subtract bet from player's chips
}

void Player::call() { // Player places down same amount of chips as previous player's bet
    // Check if player has sufficient amount of chips to make the bet
        // Fold if not enough chips
    // Subtract bet from player's chips equal to the bet made by the previous player
}

void Player::raise() { // Player bets more than what a previous player bet
    // Check if player has sufficient amount of chips and is greater than the previous bet to make the raise
    // Subtract raise from player's chips

}

void Player::fold() { // Player sits out for the rest of the round
    // Nullify the player's cards for the rest of the round (they are no longer taken into consideration when calculating the highest ranking hand)
}