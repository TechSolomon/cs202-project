/*
 * CS 202 Final Project (Spring 2021) Texas Hold'em Poker
 * By: Adrian Antonio, Benjamin Stream, Jay-Mark Pascua, & Solomon Himelbloom
*/

//
// Created by Benjamin Stream & Solomon Himelbloom on 4/8/21.
//

#include "ranking.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::sort;
using std::string;
using std::pair;
using std::vector;


void printHand(vector<pair<int, string>> hand) // prints inputed hand to console. 
{
    for (auto i: hand) {
        cout << i.first << "," << i.second << endl; // for testing purposes, prints the card value of each card inside the vector.
    }
}

vector<pair<int, string>>searchHandSuit(vector<pair<int, string>> hand) // WILL RETURN A VECTOR OF PAIRS THAT IS NOT A HAND, IT CONTAINS WHICH SUIT HAS MOST OCCOURENCES 
{
    vector<pair<int, string>> counter = { { 0,"heart" }, { 0,"club" }, { 0,"diamond" }, { 0, "spade" } };
    
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
    sort(counter.begin(), counter.end(), [](pair<int, string>&i, pair<int, string> &j) {return i.first > j.first;  });
    return counter; 
}

vector<pair<int,int>>searchHandCard(vector<pair<int, string>> hand) // WILL RETURN A VECTOR OF PAIRS THAT IS NOT A HAND, IT CONTAINS WHICH CARDS HAVE MOST OCCOURENCES 
{
    vector<pair<int, int>> counter = { { 0,1 }, { 0,2 }, { 0,3 }, { 0, 4 },{ 0,5 }, { 0,6 }, { 0,7 }, { 0, 8 },{ 0,9 }, { 0,10 },{ 0,11 }, { 0,12 }, { 0,13 }};

    for (auto i : hand) {
            counter[i.first-1].first++;    
    }
    return counter;
}



vector<pair<int, string>>getSuitCards(vector<pair<int, string>>& hand,string suit) // WILL RETURN A VECTOR OF PAIRS THAT IS NOT A HAND, IT CONTAINS WHICH SUIT HAS MOST OCCOURENCES 
{
    sort(hand.begin(), hand.end(), [](pair<int, string>& i, pair<int, string>& j) {return i.first < j.first;  });
    vector<pair<int, string>> sorted;
    vector < pair<int, string>> heart_cards;
    vector < pair<int, string>> club_cards;
    vector < pair<int, string>> diamond_cards;
    vector < pair<int, string>> spade_cards;
    for (auto i : hand) {

        if (i.second == "heart")
        {
            heart_cards.push_back(i);
          
        }
        else if (i.second == "club")
        {
            club_cards.push_back(i);
            
        }
        else if (i.second == "diamond")
        {
            diamond_cards.push_back(i);
          
        }
        else if (i.second == "spade")
        {
            spade_cards.push_back(i);
           
        }


    }
    if (suit == "heart")
    {
        return heart_cards;
    }
    else if (suit == "club")
    {
        return club_cards;
    }
    else if (suit == "diamond")
    {
        return diamond_cards;
    }
    else
    {
        return spade_cards;
    }
 
}

bool isFullHouse(vector < pair<int, string>>& hand) {
    auto temp = searchHandCard(hand);
    int counter1 = 0;
    int counter2 = 0;
    for (auto i : temp) {
        if (i.first == 2)
        {
            if (counter1 == 0)counter1++;
        }
        if (i.first == 3)
        {
            if(counter2==0) counter2++;
        }
    }
    if (counter1 + counter2 == 2) return true;
    else return false;
}

bool isFourKind(vector < pair<int, string>>& hand) {
    auto temp = searchHandCard(hand);
    for (auto i : temp) {
        if(i.first == 4)
        {
            return true;
        }
    }
    return false;
}

bool isThreeKind(vector < pair<int, string>>& hand) {
    auto temp = searchHandCard(hand);
    for (auto i : temp) {
        if (i.first == 3)
        {
            return true;
        }
    }
    return false;
}

bool isTwoPair(vector < pair<int, string>>& hand) {
    auto temp = searchHandCard(hand);
    int counter =0;
    for (auto i : temp) {
        if (i.first == 2)
        {
            counter++;
        }
    }
    if (counter == 2) return true;
    else return false;
}

bool isPair(vector < pair<int, string>>& hand) {
    auto temp = searchHandCard(hand);
    for (auto i : temp) {
        if (i.first == 2)
        {
            return true;
        }
    }
    return false;
}

bool isStraight(vector < pair<int, string>> &hand) {
    sort(hand.begin(), hand.end(), [](pair<int, string>& i, pair<int, string>& j) {return i.first < j.first;  });
    vector<pair<int, string>> temporary;
    int iterator = hand[0].first;
    int counter = 0;
    for (auto i : hand) {

        if (iterator == (i.first) - 1 || (iterator == hand[0].first && hand[0].first != hand[1].first)) // checks if the first value is a double
        {
            temporary.push_back(i);
            counter++;
        }

        iterator = i.first;
    }
    if (temporary[0].first == 11 && temporary[1].first == 12 && temporary[2].first == 13)
    {
        
        if (hand[0].first == 1) return true;
    }
    if (counter >= 5) {
        return true;
    }
    else return false;


}

bool isFlush(vector < pair<int, string>> &hand)
{
    if (searchHandSuit(hand)[0].first >= 5) {
        return true;
    }
    else return false;
}

bool isStraightFlush(vector < pair<int, string>> &hand) {
    if (isFlush(hand)) {
        auto temp = getSuitCards(hand, searchHandSuit(hand)[0].second);
        if (isStraight(temp)) {
            return true;
        }
        else return false;
    }
    else return false;
}

bool isRoyalFlush(vector < pair<int, string>> &hand) {
    
    if (searchHandSuit(hand)[0].first = 5)
    {
        auto temp = getSuitCards(hand, searchHandSuit(hand)[0].second);
        if (temp[0].first == 1 && temp[4].first == 13) {
            return true;
        }
        else return false;
    }
    
    else return false;
}

double scoreHand(vector < pair<int, string>>& hand) {
    double score =0;
    for (auto i : hand) {
        score += i.first;
    }
    return score/100;
}

HandAnalysis::HandAnalysis()
{
    cout << "Constructor" << endl;
}



double HandAnalysis::grade(vector<pair<int, string>> &hand, vector<pair<int, string>> &chand)


{
    double totalScore= 0.0;
    _combinedHand = chand; // throws chand (community hand) into the combinded hand.
    _combinedHand.insert(_combinedHand.end(), hand.begin(), hand.end()); // combinds chand and hand to create a vector 7 length 

    printHand(_combinedHand); // For testing Purposes


    // Poker Hands (highest to lowest):
// 1. Royal flush
     if(isRoyalFlush(_combinedHand)){
 totalScore = scoreHand(hand) + 10;
 }
 //2 Straight flush
     else if(isStraightFlush(_combinedHand)){
 totalScore= scoreHand(hand) + 9; 
 }
 //3. Four of a kind
     else if(isFourKind(_combinedHand)){
  totalScore = scoreHand(hand) + 8; 
 }
 //4. Full house
     else if(isFullHouse(_combinedHand)){
 totalScore = scoreHand(hand) + 7; 
 }
 //5. Flush
     else if(isFlush(_combinedHand)){
 totalScore = scoreHand(hand) + 6; 
 }
 //6. Straight
     else if(isStraight(_combinedHand)){
 totalScore = scoreHand(hand) + 5; 
 }
 //7. Three of a kind
     else if(isThreeKind(_combinedHand)){
 totalScore = scoreHand(hand) + 4; 
 }
 //8. Two pair
     else if (isTwoPair(_combinedHand)){
 totalScore =scoreHand(hand) + 3; 
 }
 //9. Pair
     else if (isPair(_combinedHand)){
 totalScore = scoreHand(hand) + 2; 
 }
 //10. High card
     else{
         sort(hand.begin(), hand.end());
         if (hand[0].first == 1) {
             totalScore = 1.99;
         }
         else {
             totalScore = hand[1].first / static_cast<double>(100) + 1;
         }
 }

     cout << "Hand Score: " << totalScore << endl; //For testing Purposes
     return totalScore;
}

