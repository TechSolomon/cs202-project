//
// Created by Benjamin Stream & Solomon Himelbloom on 4/8/21.
//

#ifndef CS202_PROJECT_RANKING_H
#define CS202_PROJECT_RANKING_H

#include <iostream>
#include <vector>

class HandAnalysis {
public:
	HandAnalysis(); // Constructor for HandAnalysis
	double grade(std::vector<std::pair<int, std::string>> &hand, std::vector<std::pair<int, std::string>> &chand);
private:
	std::vector<std::pair<int, std::string>> _combinedHand;
	//double _previous;
	//double _next;
    
};

#endif //CS202_PROJECT_RANKING_H
