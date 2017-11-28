//
// Created by shlomi on 11/25/17.
//

#include "Menu.h"
#include <iostream>
#include <limits>

using namespace std;


Menu::Menu() {
    humanPlayer = false;
    aiPlayer = false;
}


bool Menu::againstAI() {
    return aiPlayer;
}


bool Menu::againstHuman() {
    return humanPlayer;
}

void Menu::runMenu() {
    const int ai = 1;
    const int human = 2;
    int choice = 0;
    //printing menu
    cout << "Wellcome to Reversi GEVERRRRRRR!!!" << endl;
    cout << "Please select one of the options:" << endl;
    cout << "Press 1 for playing againt AI" << endl;
    cout << "Press 2 for playing against Human player" << endl;

    //ensuring valid input
    while (choice != ai && choice != human) {
        cin >> choice;
        if (!choice || choice < ai || choice > human) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Illegal choice." << endl;
            cout << "Press 1 for AI or 2 for Human player" << endl;

        }
    }
    //set the wanted player as true
    if (choice == human) {
        humanPlayer = true;
    } else {
        aiPlayer = true;
    }
}
