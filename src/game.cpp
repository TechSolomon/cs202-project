#include "game.h"
#include <SFML/Graphics.hpp>
using std::cout;
using std::endl;
using std::cin;

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

// TODO: Change file path to "../" if running OS other than Windows.
void Game::gameLoop() {
    // Starts a round of poker
	// 1. Go through each players' turn (each player can check, bet, call, etc.)
	// 2. Deal a card to the river
	// 3. If there are 5 cards in the river, check which player has the highest ranking hand
	// 4. Round ends, winning player gets the pot, loop back to beginning

    sf::RenderWindow userWindowDisplay(sf::VideoMode(1300, 600),
                                       "Texas Hold'em Poker", sf::Style::Close | sf::Style::Titlebar);

    sf::Event event;
    sf::Texture texture;

    if (!texture.loadFromFile("assets/poker-table-design.png")) {
        throw EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    sf::Font font;
    if (!font.loadFromFile("assets/sansation.ttf")) {
        throw EXIT_FAILURE;
    }

    sf::Text playerCommands("Check (space) | Bet (b) | Call (c) | Raise (r) | Fold (f)", font, 50);
    playerCommands.setFillColor(sf::Color::White);
    playerCommands.move(100.f, 0.f);

    sf::Text chipValues("Chip Presets (1-9)", font, 35);
    chipValues.setFillColor(sf::Color::White);
    chipValues.move(50.f, 500.f);

    sf::Text totalPot("Total Pot: ", font, 35);
    totalPot.setString("$" + std::to_string(_pot));
    totalPot.setFillColor(sf::Color::White);
    totalPot.move(50.f, 550.f);

    // SFML – start the event loop.
    while (userWindowDisplay.isOpen()) {
        while (userWindowDisplay.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed)
                userWindowDisplay.close();


            while (p1._money != 0) { // Game keeps going until p1 runs out of money
                std::vector<displayCard> displayRiver{};
                cardDisplayValue(displayRiver, _river);
                initialPosition(displayRiver, 100.0f, 150.0f);//change this to where it draw in the screen
                offsetPosition(displayRiver, 150.f);
                userWindowDisplay.clear();            
                userWindowDisplay.draw(sprite);
                userWindowDisplay.draw(totalPot);
                userWindowDisplay.draw(chipValues);
                userWindowDisplay.draw(playerCommands);
                screenCards(displayRiver, userWindowDisplay);//draws river
                userWindowDisplay.display();
                std::cout << "CURRENT POT: " << _pot << std::endl;
                totalPot.setString("$" + std::to_string(_pot));
                if (_roundPhase == 0) {	// Betting phase
                    std::cout << "PLAYER 1'S TURN" << std::endl;
                    getPlayerInput(p1);
                    std::cout << "PLAYER 2'S TURN" << std::endl;
                    getPlayerInput(p2);
                    std::cout << "PLAYER 3'S TURN" << std::endl;
                    getPlayerInput(p3);
                    std::cout << "PLAYER 4'S TURN" << std::endl;
                    getPlayerInput(p4);

                    if (_river.size() == 0) { // Move on to dealing 3 cards to river (case 1) if everyone bet/check
                        if (everyoneCalled())
                            _roundPhase = 1;
                        else if (everyoneChecked())
                            _roundPhase = 1;
                        else {
                            letPlayerCallARaise();
                            _roundPhase = 1;
                        }
                    }

                    else if (_river.size() == 3 || _river.size() == 4) { // Move on to dealing 1 card to river (case 2) if everyone bet/check
                        if (everyoneCalled())
                            _roundPhase = 2;
                        else if (everyoneChecked())
                            _roundPhase = 2;
                        else {
                            letPlayerCallARaise();
                            _roundPhase = 2;
                        }
                    }

                    else if (_river.size() == 5) { // Move on to dealing determining winner (case 3) if everyone bet/check
                        if (everyoneCalled())
                            _roundPhase = 3;
                        else if (everyoneChecked())
                            _roundPhase = 3;
                        else {
                            letPlayerCallARaise();
                            _roundPhase = 3;
                        }
                    }
                }

                else if (_roundPhase == 1) { // Deal 3 cards to river
                    std::cout << "DEALING 3 CARDS TO RIVER" << std::endl;
                    _cards.playableCards.pop_back(); // Remove a card before dealing (standard thing they do in poker before dealing to river)
                    _cards.drawCards(_river, 3);
                    _roundPhase = 0; // Go back to betting phase
                }

                else if (_roundPhase == 2) { // Deal 1 card to river
                    std::cout << "DEALING 1 CARD TO RIVER" << std::endl;
                    _cards.playableCards.pop_back(); // Remove a card before dealing (standard thing they do in poker before dealing to river)
                    _cards.drawCards(_river, 1);
                    _roundPhase = 0; // Go back to betting phase
                }

                else if (_roundPhase == 3) { // Determine winner then reset cards
                    std::cout << "DETERMINING WINNER" << std::endl;
                    p1._score = _analysis.grade(p1.getHand(), _river);
                    p2._score = _analysis.grade(p2.getHand(), _river);
                    p3._score = _analysis.grade(p3.getHand(), _river);
                    p4._score = _analysis.grade(p4.getHand(), _river);

                    determineWinner();
                    resetRound();

                }
                std::cout << "BROKE OUT OF LOOP" << _roundPhase << std::endl;
                
            }
           
        }
        

    }
    
}

void Game::resetRound() {
    _cards.resetCard();
    _cards.shuffle();
    _pot = 0;
    _currentBet = 0;
    _highestScore = 0;
    _roundPhase = 0;
    this->setup(_numPlayers);
}

void Game::getPlayerInput(Player& p) {
    while (true) { // Wait for input then break when found
        int bet; // Player's inputted amount of money

        // Keyboard initial input (1-9) to change amount of chips.
        // Use b/c/r/f for bet, call, raise, and fold.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { // Player checks (moves on to next player's turn)
            sf::sleep((sf::milliseconds(500)));
            std::cout << "KEYBOARD CHECK (CHECK). Space key was pressed." << std::endl;
            p.check();
            break;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
            // BET
            sf::sleep((sf::milliseconds(500)));
            std::cout << "KEYBOARD INPUT (BET). B key was pressed." << std::endl;
            bet = getNumericInput(); 
            p.bet(bet);
            setCurrentBet(p.playerCurrentBet);
            setPot(p.playerCurrentBet);
            break;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
            // CALL
            sf::sleep((sf::milliseconds(500)));
            std::cout << "KEYBOARD INPUT (CALL). C key was pressed." << std::endl;
            p.call(getCurrentBet());
            setCurrentBet(p.playerCurrentBet);
            setPot(p.playerCurrentBet);
            break;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            // RAISE
            sf::sleep((sf::milliseconds(500)));
            std::cout << "KEYBOARD INPUT (RAISE). R key was pressed." << std::endl;
            bet = getNumericInput();
            p.raise(*this, bet);
            setCurrentBet(p.playerCurrentBet);
            setPot(p.playerCurrentBet);
            break;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            // FOLD
            sf::sleep((sf::milliseconds(500)));
            std::cout << "KEYBOARD INPUT (FOLD). F key was pressed." << std::endl;
            p.fold();
            break;
        }
    }
}

int Game::getNumericInput() const { // Gets money input from player
    int bet; // Amount of money
    std::cout << "[1] = $1 | [2] = $2 | [3] = $5 | [4] = $10 | [5] = $20 | [6] = $25 | [7] = $50 | [8] = $100 | [9] = $500 | [0] = $1000" << std::endl;
    while (true) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            // Num1 = $1
            sf::sleep((sf::milliseconds(500)));
            std::cout << "Key 1 was pressed." << std::endl;
            bet = 1;
            break;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
            // Num2 = $2
            sf::sleep((sf::milliseconds(500)));
            std::cout << "Key 2 was pressed." << std::endl;
            bet = 2;
            break;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
            // Num3 = $5
            sf::sleep((sf::milliseconds(500)));
            std::cout << "Key 3 was pressed." << std::endl;
            bet = 5;
            break;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
            // Num4 = $10
            sf::sleep((sf::milliseconds(500)));
            std::cout << "Key 4 was pressed." << std::endl;
            bet = 10;
            break;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
            // Num5 = $20
            sf::sleep((sf::milliseconds(500)));
            std::cout << "Key 5 was pressed." << std::endl;
            bet = 20;
            break;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
            // Num6 = $25
            sf::sleep((sf::milliseconds(500)));
            std::cout << "Key 6 was pressed." << std::endl;
            bet = 25;
            break;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
            // Num7 = $50
            sf::sleep((sf::milliseconds(500)));
            std::cout << "Key 7 was pressed." << std::endl;
            bet = 50;
            break;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
            // Num8 = $100
            sf::sleep((sf::milliseconds(500)));
            std::cout << "Key 8 was pressed." << std::endl;
            bet = 100;
            break;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
            // Num9 = $500
            sf::sleep((sf::milliseconds(500)));
            std::cout << "Key 9 was pressed." << std::endl;
            bet = 500;
            break;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
            // Num0 = $1000
            sf::sleep((sf::milliseconds(500)));
            std::cout << "Key 0 was pressed." << std::endl;
            std::cout << "BROKE OUT OF LOOP" << _roundPhase << std::endl;
            bet = 1000;
            break;
        }
    }
        return bet;
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

	std::vector<Player> playersStillPlaying; // Consider only players who are still playing
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

bool Game::everyoneChecked() { // Advances round phase if everyone has 

    std::vector<Player> playersStillPlaying; // Consider only players who are still playing
    if (p1._isFolded == false)
        playersStillPlaying.push_back(p1);
    if (p2._isFolded == false)
        playersStillPlaying.push_back(p2);
    if (p3._isFolded == false)
        playersStillPlaying.push_back(p3);
    if (p4._isFolded == false)
        playersStillPlaying.push_back(p4);

    for (const auto& x : playersStillPlaying) { // Returns false if not everyone checked
        if (x._checked == false)
            return false;
    }
    return true;
}

void Game::letPlayerCallARaise() {
    if (p1.playerCurrentBet != _currentBet) {
        std::cout << "LET PLAYER CALL A RAISE: P1" << std::endl;
        getPlayerInput(p1);
    }
    if (p2.playerCurrentBet != _currentBet) {
        std::cout << "LET PLAYER CALL A RAISE: P1" << std::endl;
        getPlayerInput(p2);
    }
    if (p3.playerCurrentBet != _currentBet) {
        std::cout << "LET PLAYER CALL A RAISE: P1" << std::endl;
        getPlayerInput(p3);
    }
    if (p4.playerCurrentBet != _currentBet) {
        std::cout << "LET PLAYER CALL A RAISE: P1" << std::endl;
        getPlayerInput(p4);
    }
}

void Game::determineWinner() {
    std::vector<double> scores; // Contain all the scores

    scores.push_back(p1._score);
    scores.push_back(p2._score);
    scores.push_back(p3._score);
    scores.push_back(p4._score);

    if (p1._score > _highestScore) // Find what is the highest score
        _highestScore = p1._score;

    if (p2._score > _highestScore)
        _highestScore = p2._score;

    if (p3._score > _highestScore)
        _highestScore = p3._score;

    if (p4._score > _highestScore)
        _highestScore = p4._score;

    if (_highestScore == p1._score) { // Find who has the highest score, give them the pot
        std::cout << "PLAYER 1 WINS" << std::endl;
        p1._money += _pot;
    }
    else if (_highestScore == p2._score) {
        std::cout << "PLAYER 2 WINS" << std::endl;
        p2._money += _pot;
    }
    else if (_highestScore == p3._score) {
        std::cout << "PLAYER 3 WINS" << std::endl;
        p3._money += _pot;
    }
    else if (_highestScore == p4._score) {
        std::cout << "PLAYER 4 WINS" << std::endl;
        p4._money += _pot;
    }
}