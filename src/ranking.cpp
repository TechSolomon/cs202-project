//
// Created by Benjamin Stream & Solomon Himelbloom on 4/8/21. TEST BRANCH
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



bool incrementing_number(std::pair<int,std::string> i, std::pair<int, std::string> j) {
    return j.first == i.first - 1;
}

bool same_suit(std::pair<int, std::string> i, std::pair<int, std::string> j) {

    return i.second < j.second;
}

bool same_number(std::pair<int, std::string> i, std::pair<int, std::string> j) {
    if (i.first == j.first) return true;
    else return false;
   
}

void printHand(std::vector<std::pair<int, std::string>> hand) // prints inputed hand to console. 
{
    for (auto i: hand) {
        cout << i.first << "," << i.second << endl; // for testing purposes, prints the card value of each card inside the vector.
    }
}

//Taken from https://codereview.stackexchange.com/questions/173382/sorting-elements-according-to-frequency-of-occurence-in-c
template<class T>
void sortByFreq2(std::vector<T>& v)
{
    std::unordered_map<T, size_t> count;

    for (T i : v) {
        count[i]++;
    }

    std::sort(
        v.begin(),
        v.end(),
        [&count](T const& a, T const& b) {
            if (a == b) {
                return false;
            }
            if (count[a] > count[b]) {
                return true;
            }
            else if (count[a] < count[b]) {
                return false;
            }
            return a < b;
        });
}




std::vector<std::pair<int, std::string>>searchHandSuit(std::vector<std::pair<int, std::string>> hand) // WILL RETURN A VECTOR OF PAIRS THAT IS NOT A HAND, IT CONTAINS WHICH SUIT HAS MOST OCCOURENCES 
{
    std::vector<std::pair<int, std::string>> counter = { { 0,"heart" }, { 0,"club" }, { 0,"diamond" }, { 0, "spade" } };
    
    for (auto i: hand) {

        if (i.second == "heart") 
        {
            counter[0].first++;
        }
        else if (i.second == "club") 
        {
            counter[1].first++;
        } 
        else if (i.second == "diamond")
        {
            counter[2].first++;
        }
        else if (i.second == "spade") 
        {
            counter[3].first++;
        } 
    }
    sort(counter.begin(), counter.end(), [](std::pair<int, std::string>&i, std::pair<int, std::string> &j) {return i.first > j.first;  });
    return counter; 
}

std::vector<std::pair<int, std::string>>sortyByFreq(std::vector<std::pair<int, std::string>>& hand) //returns vector sorted by occourences.
{
    auto tempHand = hand;
    auto temp = searchHandSuit(hand);
    //sort(tempHand.begin(), tempHand.end(), same_suit);
        std::sort(tempHand.begin(),tempHand.end(),
            [&temp](std::pair<int, std::string> const& a, std::pair<int, std::string> const& b) {
                for (auto i : temp) {
                    if (i.second == a.second ) {

                        if (a.second == b.second) {
                            return a.first < b.first;
                        }
                        else return false;

                    }
                }
              /*  else if (temp[1].second == a.second) {

                    if (a.second == b.second) {
                        return a.first < b.first;
                    }
                    else return false;

                }
                else if (temp[2].second == a.second) {

                    if (a.second == b.second) {
                        return a.first < b.first;
                    }
                    else return false;

                }
                else if (temp[3].second == a.second) {

                    if (a.second == b.second) {
                        return a.first < b.first;
                    }
                    else return false;

                }
                else return false;*/

            });
    
    return tempHand;

}

bool isStraight(vector < std::pair<int, std::string>> hand) {
    sort(hand.begin(), hand.end(), [](std::pair<int, std::string>& i, std::pair<int, std::string>& j) {return i.first < j.first;  });
    int iterator = hand[0].first;
    int counter = 0;
    for (auto i : hand) {
        cout << i.first << endl;
        if (iterator == (i.first) - 1)
        {
            cout << "Counted!" << endl;
            counter++;
        }

        iterator = i.first;
    }
    if (hand[0].first == 1 && hand[6].first == 13 && counter == 4) {
        return true;
    }
    if (counter >= 5) {
        return true;
    }
    else return false;

}

bool isFlush(vector < std::pair<int, std::string>> hand)
{
    if (searchHandSuit(hand)[0].first >= 5) {
        return true;
    }
    else return false;
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

    //sort(_combinedHand.begin(), _combinedHand.end(), same_suit);
    cout << "Sorted Via Same Suit" << endl;
    printHand(sortyByFreq(_combinedHand));
    cout << "Occourences of Suit" << endl;
    printHand(searchHandSuit(_combinedHand));


    vector<std::pair<int, std::string>> straight = { {1,"spade"},{4,"heart"}, {5,"diamond"},{6,"heart"}, {7,"spade"}, {8,"diamond"}, {13,"spade"} };
    cout << "Straight Test" << endl;
    printHand(straight);
    cout << "0 = False, 1 = True" << endl;
    cout <<"Truth Value:" << isStraight(straight) << endl;
    cout << "Flush Test" << endl;
    printHand(straight);
    cout << "0 = False, 1 = True" << endl;
    cout << "Truth Value:" << isFlush(straight) << endl;

    // Poker Hands (highest to lowest):
// 1. Royal flush
//     if(){}
// 2 Straight flush
//     else if(){}
// 3. Four of a kind
//     else if(){}
// 4. Full house
//     else if(){}
// 5. Flush
//     else if(){}
// 6. Straight
//     else if(){}
// 7. Three of a kind
//     else if(){}
// 8. Two pair
//     else if(){}
// 9. Pair
//     else if(){}
// 10. High card
//  else {
//  sort(hand.begin(), hand.end());
//  return hand[0].first / 100; 
//}








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


