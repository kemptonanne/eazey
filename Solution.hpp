//
//  Solution.hpp
//  ChatBot
//
//  Created by Kempton McCarty on 1/21/20.
//  Copyright © 2020 Kempton McCarty. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    std::string desc;
    int num;
// 1: happiness
// 2: sadness
// 3: fear
// 4: disgust
// 5: anger
    Solution();
    Solution(std::string, int num);
    void setName(std::string);
    void setNum(int);
    std::string getName();
    int getNum();
    std::string toString();
};

#endif /* Emotion_hpp */
