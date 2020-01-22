//
//  User.hpp
//  ChatBot
//
//  Created by Kempton McCarty on 1/21/20.
//  Copyright © 2020 Kempton McCarty. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include "Emotion.hpp"

#include <stdio.h>
#include <string>
using namespace std;

class User {
private:
    std::string name;
    Emotion emotion;
public:
    User();
    User(std::string, Emotion);
    void setName(std::string);
    void setEmotion(Emotion);
    std::string getName();
    Emotion getEmotion();
    std::string toString();
};

#endif /* User_hpp */
