//
// Created by Benjamin Stream & Solomon Himelbloom on 4/8/21.
//

#include "ranking.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::map;
using std::ofstream;
using std::reverse;
using std::sort;
using std::string;
using std::vector;

// Poker Hands (highest to lowest):
// 1. Royal flush
// 2 Straight flush
// 3. Four of a kind
// 4. Full house
// 5. Flush
// 6. Straight
// 7. Three of a kind
// 8. Two pair
// 9. Pair
// 10. High card
void printHand(std::vector<std::pair<int, std::string>> hand) // prints inputed hand to console. 
{
    for (int i = 0; i < hand.size(); i++) {
        cout << hand[i].first << "," << hand[i].second << endl; // for testing purposes, prints the card value of each card inside the vector.
    }
}

HandAnalysis::HandAnalysis()
{
    cout << "Constructor" << endl;
}

double HandAnalysis::grade(std::vector<std::pair<int, std::string>> hand, std::vector<std::pair<int, std::string>> chand)
{
    _combinedHand = chand; // throws chand (community hand) into the combinded hand.
    _combinedHand.insert(_combinedHand.end(), hand.begin(), hand.end()); // combinds chand and hand to create a vector 7 length 
    
    printHand(_combinedHand);
    sort(_combinedHand.begin(),_combinedHand.end()); // sorts by int value, ie Ace, 2,3,...,J,Q,K
    printHand(_combinedHand);
    return 0.0;
}




int sample() {


    //Hand has 2 cards
    // Community hand has 5
    // vector community + personal hand = 7
    // sort combinded hand then comepare 
    // do this for every individual player
    // assign score, biggest score wins the pot
    //break hand scores into base score + (card value / 100) ie 2 pair is 3 points, so a 2 pair of 10s is 3.1 points, a 2 pair of 2s is 3.02 points
    // 
    // TODO:
    // community hand (vector -> filled to 5 spaces)
    // compared to attributes of pairs to a set list of hands (cases)
    // example: full house, etc.
    // Assign the rankings up to a max value.
    // Final comparison on 5th card.
    // Sum of values for conflicting hands.

    // Steps:
    // 1 – table algorithm for ranking (already have the cards in Deck.cpp)
    // 2 – interact with cards based on rules

    return 0;
}

