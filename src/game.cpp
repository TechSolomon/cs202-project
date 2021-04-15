#include "game.h"

Game::Game() {
}

Game::~Game() {
}

void Game::setup() { // Constructs deck and player objects before starting the game
	Deck cards; // Sets up deck of cards
	Player player(cards); // Sets up player and assigns them their hand (2 cards)
}

void Game::gameLoop() { // Starts a round of poker
	// 1. Go through each players' turn (each player can check, bet, call, etc.)
	// 2. Deal a card to the river
	// 3. If there are 5 cards in the river, check which player has the highest ranking hand
	// 4. Round ends, winning player gets the pot, loop back to beginning
}