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

//Hello

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

std::vector<std::pair<int, std::string>>getSuitCards(std::vector<std::pair<int, std::string>>& hand,string suit) // WILL RETURN A VECTOR OF PAIRS THAT IS NOT A HAND, IT CONTAINS WHICH SUIT HAS MOST OCCOURENCES 
{
    sort(hand.begin(), hand.end(), [](std::pair<int, std::string>& i, std::pair<int, std::string>& j) {return i.first < j.first;  });
    std::vector<std::pair<int, std::string>> sorted;
    std::vector < std::pair<int, std::string>> heart_cards;
    std::vector < std::pair<int, std::string>> club_cards;
    std::vector < std::pair<int, std::string>> diamond_cards;
    std::vector < std::pair<int, std::string>> spade_cards;
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
    if(suit =="heart" )
    {
        return heart_cards;
    }
    if (suit == "club")
    {
        return club_cards;
    } if (suit == "diamond")
    {
        return diamond_cards;
    } if (suit == "spade")
    {
        return spade_cards;
    }
}

bool isStraight(vector < std::pair<int, std::string>> &hand) {
    sort(hand.begin(), hand.end(), [](std::pair<int, std::string>& i, std::pair<int, std::string>& j) {return i.first < j.first;  });
    int iterator = hand[0].first;
    int counter = 0;
    for (auto i : hand) {
        
        if (iterator == (i.first) - 1|| (iterator == hand[0].first && hand[0].first != hand[1].first )) // checks if the first value is a double
        {
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

bool isbetterStraight(vector < std::pair<int, std::string>> &hand) {
    sort(hand.begin(), hand.end(), [](std::pair<int, std::string>& i, std::pair<int, std::string>& j) {return i.first < j.first;  });
    vector<std::pair<int, std::string>> temporary;
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
    //printHand(temporary);
    if (temporary[0].first == 11 && temporary[1].first == 12 && temporary[2].first == 13)
    {
        
        if (hand[0].first == 1) return true;
    }
    if (counter >= 5) {
        return true;
    }
    else return false;


}

bool isFlush(vector < std::pair<int, std::string>> &hand)
{
    if (searchHandSuit(hand)[0].first >= 5) {
        return true;
    }
    else return false;
}

bool isStraightFlush(vector < std::pair<int, std::string>> &hand) {
    sort(hand.begin(), hand.end(), [](std::pair<int, std::string>& i, std::pair<int, std::string>& j) {return i.first < j.first;  });
    printHand(hand);
    int iteratorInt = hand[0].first;
    std::string iteratorString=searchHandSuit(hand)[0].second;

    int counter = 0;
    for (int i = 0; i < hand.size(); i++) {
     
        if ((iteratorInt == (hand[i].first) -  1 || (iteratorInt == hand[0].first && hand[0].first != hand[1].first)) && hand[i].second == iteratorString)
        {
            counter++;
        }

        iteratorInt = hand[i].first;
    }
    
    if (counter >= 5) {
        return true;
    }
    else return false;

}

bool isRoyalFlush(vector < std::pair<int, std::string>> &hand) {
    
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

double scoreHand(vector < std::pair<int, std::string>>& hand) {
    double score;
    for (auto i : hand) {
        score += i.first;
    }
    return score/100;
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

    //cout << "Not Sorted" << endl;
    //printHand(_combinedHand);

    //sort(_combinedHand.begin(),_combinedHand.end()); // sorts by int value, ie Ace, 2,3,...,J,Q,K
    //cout << "Sorted Via Card Value" << endl;
    //printHand(_combinedHand);

    //sort(_combinedHand.begin(), _combinedHand.end(), same_number);
    //cout << "Sorted Via Same Value" << endl;
    //printHand(_combinedHand);

    ////sort(_combinedHand.begin(), _combinedHand.end(), same_suit);
    //cout << "Sorted Via Same Suit" << endl;
    //printHand(_combinedHand);

    //cout << "Occourences of Suit" << endl;
    //printHand(searchHandSuit(_combinedHand));


    vector<std::pair<int, std::string>> straight = { {1,"spade"},{3,"diamond"}, {10,"spade"},{11,"spade"}, {13,"spade"}, {12,"spade"}, {13,"diamond"} };


    cout << isRoyalFlush(straight) << endl;
   // cout << "Straight Test" << endl;
   //// printHand(straight);
   // cout << "0 = False, 1 = True" << endl;
   // cout <<"Truth Value:" << isStraight(straight) << endl;

    //cout << "Flush Test" << endl;
    ////printHand(straight);
    //cout << "0 = False, 1 = True" << endl;
    //cout << "Truth Value:" << isFlush(straight) << endl;

    //cout << "Straight Flush Test" << endl;
    //printHand(straight);
    //cout << "0 = False, 1 = True" << endl;
   //cout << "Truth Value:" << isStraightFlush(straight) << endl;
    // Poker Hands (highest to lowest):
// 1. Royal flush
     if(isRoyalFlush(_combinedHand)){
 totalScore = scoreHand(hand) + 10;
 }
 ////2 Straight flush
 //    else if(isStraight(_combinedHand)){
 //totalScore= scoreHand(hand) + 9; 
 //}
 ////3. Four of a kind
 //    else if(){
 // totalScore = scoreHand(hand) + 8; 
 //}
 ////4. Full house
 //    else if(){
 //totalScore = scoreHand(hand) + 7; 
 //}
 ////5. Flush
 //    else if(){
 //totalScore = scoreHand(hand) + 6; 
 //}
 ////6. Straight
 //    else if(){
 //totalScore = scoreHand(hand) + 5; 
 //}
 ////7. Three of a kind
 //    else if(){
 //totalScore = scoreHand(hand) + 4; 
 //}
 ////8. Two pair
 //    else if ()
 //    {
 //totalScore =scoreHand(hand) + 3; 
 //}
 ////9. Pair
 //    else if ()
 //    {
 //totalScore = scoreHand(hand) + 2; 
 //}
 //10. High card
  else{
         sort(hand.begin(), hand.end());
         if (hand[0].first == 1) {
             totalScore = 1.99;
         }
         else {
             totalScore = hand[1].first / 100 + 1;
         }
 }

     cout << totalScore << endl;
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


