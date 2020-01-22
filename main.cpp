//
//  main.cpp
//  ChatBot
//
//  Created by Kempton McCarty on 1/21/20.
//  Copyright © 2020 Kempton McCarty. All rights reserved.
//

#include "User.hpp"
#include "Emotion.hpp"
#include "Solution.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

User user;
std::string toLowercase(std::string input);
void findEmotion(std::string input);
void findSolution(Emotion input);

/* main method */
int main() {
    cout << "Eazey is here to help you manage your mental health by providing tips based on your emotions. You may respond with full sentences and Eazey will analyze them." << endl;
    cout << "EAZEY: What's your name?" << endl;
    cout << "YOU: ";
    std::string input;
    getline(cin, input);
    user.setName(input);
    
    cout << "EAZEY: Hi " << user.getName() << "! How are you feeling today?" << endl;
    cout << "YOU: ";
    getline(cin, input);
    findEmotion(toLowercase(input));
    
    while ( ((user.getEmotion()).getName() == "") && ((user.getEmotion()).getNum() == 0) ) {
        cout << "EAZEY: I couldn't find that emotion. Try one of these: " << endl << "Happy" << endl << "Sad" << endl << "Nervous" << endl << "Disgusted" << endl << "Angry" << endl;
        cout << "YOU: ";
        getline(cin, input);
        findEmotion(toLowercase(input));
    }
    
    cout << "EAZEY: I can tell that you are feeling " << (user.getEmotion()).toString() << ". Would you like to hear some tips?" << endl;
        cout << "YOU: ";
        getline(cin, input);
    
    while ( (toLowercase(input)) != "yes" && (toLowercase(input)) != "no" ) {
        cout << "EAZEY: I don't recognize your response. Please type 'yes' or 'no'." << endl;
        cout << "YOU: ";
        getline(cin, input);
    }
    if ((toLowercase(input)) == "yes") {
        cout << "EAZEY: Okay, here's a great solution: ";
        findSolution( user.getEmotion() );
        cout << "EAZEY: Do you want to hear more tips?" << endl;
        cout << "YOU: ";
        getline(cin, input);
        while ( (toLowercase(input)) != "yes" && (toLowercase(input)) != "no" ) {
            cout << "EAZEY: I don't recognize your response. Please type 'yes' or 'no'." << endl;
            cout << "YOU: ";
            getline(cin, input);
        }
        while ((toLowercase(input)) == "yes") {
            cout << "EAZEY: Okay, here's another great solution: ";
            findSolution( user.getEmotion() );
            cout << "EAZEY: Do you want to hear more tips?" << endl;
            cout << "YOU: ";
            getline(cin, input);
        }
    }
    if ((toLowercase(input)) == "no") {
        cout << "EAZEY: It was great to talk to you today, goodbye!" << endl;
    }
    return 0;
}

std::string toLowercase(std::string input) {
    std::for_each(input.begin(), input.end(), [](char & c) {
        c = ::tolower(c);
    });
    return input;
}

void findEmotion(std::string input) {
    std::ifstream file;
    file.open("Emotions.txt");
    if (!file) {
        cout << "Error in opening the file" << endl;
    }
    vector<Emotion> emotions;
    Emotion temp;
    while (file >> temp.name >> temp.num) {
        emotions.push_back(temp);
    }
    for (const auto& emotion : emotions) {
        if (input.find(emotion.name) != std::string::npos) {
            user.setEmotion(emotion);
        }
    }
}

void findSolution(Emotion input) {
    std::ifstream file;
    file.open("Solutions.txt");
    if (!file) {
        cout << "Error in opening the file" << endl;
    }
    vector<Solution> solutions;
    Solution temp;
    std::string skip;
    while (file >> std::quoted(temp.desc) >> temp.num) {
        solutions.push_back(temp);
    }

    int count = 0;
    for (const auto& solution : solutions) {
        if (solution.num == input.num) {
            count++;
        }
    }
    std::string arr[count];
    int i = 0;
    for (const auto& solution : solutions) {
        if (solution.num == input.num) {
            arr[i] = solution.desc;
            i++;
        }
    }
    
    int randomIndex = (rand() % count);
    cout << arr[randomIndex] << endl;
}
