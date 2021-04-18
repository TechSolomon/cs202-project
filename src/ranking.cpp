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
bool incrementing_number(std::pair<int,std::string> i, std::pair<int, std::string> j) {
    return j.first == i.first - 1;
}

bool same_suit(std::pair<int, std::string> i, std::pair<int, std::string> j) {
    return i.second < j.second;
}

bool same_number(std::pair<int, std::string> i, std::pair<int, std::string> j) {
    return i.first == j.first;
   
}

bool idk(std::pair<int, std::string> i, std::pair<int, std::string> j) {
    if (i.first == j.first) return true;
    else return false;
}
void printHand(std::vector<std::pair<int, std::string>> hand) // prints inputed hand to console. 
{
    for (int i = 0; i < hand.size(); i++) {
        cout << hand[i].first << "," << hand[i].second << endl; // for testing purposes, prints the card value of each card inside the vector.
    }
}

std::pair<int, std::string>searchHandSuit(std::vector<std::pair<int, std::string>> hand) // WILL RETURN A PAIR THAT IS NOT A CARD, IT CONTAINS WHICH SUIT HAS MOST OCCOURENCES 
{
    std::vector<std::pair<int, std::string>> counter = { { 0,"hearts" }, { 0,"clubs" }, { 0,"diamonds" }, { 0, "spades" } };
    
    for (int i = 0; i < hand.size(); i++) {

        if (hand[i].second == "heart") 
        {
            counter[0].first++;
        }
        else if (hand[i].second == "club") 
        {
            counter[1].first++;
        } 
        else if (hand[i].second == "diamond")
        {
            counter[2].first++;
        }
        else if (hand[i].second == "spade") 
        {
            counter[3].first++;
        } 
    }
    sort(counter.begin(), counter.end());
    return counter[3]; // sorts opposite of the hand analysis i.e. 9,8,...,2,1 so return last value in counter.
}

HandAnalysis::HandAnalysis()
{
    cout << "Constructor" << endl;
}

double HandAnalysis::grade(std::vector<std::pair<int, std::string>> &hand, std::vector<std::pair<int, std::string>> &chand)
{
    double totalScore= 0.0;
    _combinedHand = chand; // throws chand (community hand) into the combinded hand.
    _combinedHand.insert(_combinedHand.end(), hand.begin(), hand.end()); // combinds chand and hand to create a vector 7 length 

    cout << "Not Sorted" << endl;
    printHand(_combinedHand);

    sort(_combinedHand.begin(),_combinedHand.end()); // sorts by int value, ie Ace, 2,3,...,J,Q,K
    cout << "Sorted Via Card Value" << endl;
    printHand(_combinedHand);

    sort(_combinedHand.begin(), _combinedHand.end(), same_number);
    cout << "Sorted Via Same Value" << endl;
    printHand(_combinedHand);

    sort(_combinedHand.begin(), _combinedHand.end(), same_suit);
    cout << "Sorted Via Same Suit" << endl;
    printHand(_combinedHand);
    cout << searchHandSuit(_combinedHand).first <<" "<<searchHandSuit(_combinedHand).second << endl;

    return totalScore;
}
// the dream of this function is to be ran at the end of the round and then will return a value (double) for each player, we can then compare those values to give the winner the pot


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


