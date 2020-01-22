//
//  Emotion.hpp
//  ChatBot
//
//  Created by Kempton McCarty on 1/21/20.
//  Copyright © 2020 Kempton McCarty. All rights reserved.
//

#ifndef Emotion_hpp
#define Emotion_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Emotion {
public:
    std::string name;
    int num;
// 1: happiness
// 2: sadness
// 3: fear
// 4: disgust
// 5: anger
    Emotion();
    Emotion(std::string, int num);
    void setName(std::string);
    void setNum(int);
    std::string getName();
    int getNum();
    std::string toString();
};

#endif /* Emotion_hpp */
