//
//  Emotion.cpp
//  ChatBot
//
//  Created by Kempton McCarty on 1/21/20.
//  Copyright © 2020 Kempton McCarty. All rights reserved.
//

#include "Emotion.hpp"

Emotion::Emotion() {
    name = "";
    num = 0;
}

Emotion::Emotion(std::string inName, int inNum) {
    name = inName;
    num = inNum;
}

void Emotion::setName (std::string inName) { name = inName; }
void Emotion::setNum(int inNum) { num = inNum; }

std::string Emotion::getName() { return name; }
int Emotion::getNum() { return num; }

std::string Emotion::toString() { return name;}
