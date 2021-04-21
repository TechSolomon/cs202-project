#include "game.h"

Game::Game() {
}

Game::~Game() {
}

void Game::setup(int& players) { // Constructs deck and player objects before starting the game
	_numPlayers = players;
	_cards.shuffle(); // Sets up deck of cards

	if (players > 0) {
		p1.dealCards(_cards);
		players--;
	}

	if (players > 0) {
		p2.dealCards(_cards);
		players--;
	}

	if (players > 0) {
		p3.dealCards(_cards);
		players--;
	}

	if (players > 0) {
		p4.dealCards(_cards);
		players--;
	}

}

void Game::gameLoop(Game& game) { // Starts a round of poker
	// 1. Go through each players' turn (each player can check, bet, call, etc.)
	switch (_roundPhase) {
	case 0:	// Betting phase
		p1.getPlayerInput(game, game.p1);
		p2.getPlayerInput(game, game.p2);
		p3.getPlayerInput(game, game.p3);
		p4.getPlayerInput(game, game.p4);
		if (everyoneCalled()) // Move on to dealing cards to river if everyone bet
			_roundPhase = 1;
		break;
	case 1: // Deal 3 cards to river
		_cards.playableCards.pop_back(); // Remove a card before dealing (standard thing they do in poker before dealing to river)
		_cards.drawCards(_river, 3);
		_roundPhase = 0; // Go back to betting phase
		break;
	case 2: // Deal 1 card to river
		_cards.playableCards.pop_back(); // Remove a card before dealing (standard thing they do in poker before dealing to river)
		_cards.drawCards(_river, 1);
		_roundPhase = 0; // Go back to betting phase
		break;
	case 3:
		break;
	default:
		break;
	}
	// 2. Deal a card to the river
	// 3. If there are 5 cards in the river, check which player has the highest ranking hand
	// 4. Round ends, winning player gets the pot, loop back to beginning
	

}

void Game::setPot(const int& bet) {
	_pot += bet;
}

int Game::getPot(const int& bet) const {
	return _pot;
}

void Game::setCurrentBet(const int& bet) {
	_currentBet = bet;
}

int Game::getCurrentBet() const {
	return _currentBet;
}

bool Game::everyoneCalled() { // Advances round phase if everyone has called

	std::vector<Player> playersStillPlaying;
	if (p1._isFolded == false)
		playersStillPlaying.push_back(p1);
	if (p2._isFolded == false)
		playersStillPlaying.push_back(p2);
	if (p3._isFolded == false)
		playersStillPlaying.push_back(p3);
	if (p4._isFolded == false)
		playersStillPlaying.push_back(p4);

	for (const auto& x : playersStillPlaying) {
		if (x.playerCurrentBet != _currentBet)
			return false;
	}
	return true;
}
