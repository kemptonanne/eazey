//
//  User.cpp
//  ChatBot
//
//  Created by Kempton McCarty on 1/21/20.
//  Copyright © 2020 Kempton McCarty. All rights reserved.
//

#include "User.hpp"

User::User() {
    name = "";
    emotion = Emotion();
}

User::User(std::string inName, Emotion inEmotion) {
    name = inName;
    emotion = inEmotion;
}

void User::setName (std::string inName) { name = inName; }
void User::setEmotion(Emotion inEmotion) { emotion = inEmotion; }

std::string User::getName() { return name; }
Emotion User::getEmotion() { return emotion; }

std::string User::toString() { return name; }
