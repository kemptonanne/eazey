//
//  Solution.cpp
//  ChatBot
//
//  Created by Kempton McCarty on 1/21/20.
//  Copyright © 2020 Kempton McCarty. All rights reserved.
//

#include "Solution.hpp"

Solution::Solution() {
    desc = "";
    num = 0;
}

Solution::Solution(std::string inDesc, int inNum) {
    desc = inDesc;
    num = inNum;
}

void Solution::setName (std::string inDesc) { desc = inDesc; }
void Solution::setNum(int inNum) { num = inNum; }

std::string Solution::getName() { return desc; }
int Solution::getNum() { return num; }

std::string Solution::toString() { return desc;}
