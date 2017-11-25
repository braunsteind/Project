#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(int color) : Player(color) {}

void HumanPlayer::playMove(vector<int> &moves, vector<int> &choice) {
    int row, col;
    //get row and col, -1 in order to use in the vector.
    cin >> row >> col;
    if (!cin) {
        //user didn't input a number.
        cin.clear(); //reset fail bit.
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
        choice.push_back(-1);
        choice.push_back(-1);
    } else {
        row--;
        col--;
        choice.push_back(row);
        choice.push_back(col);
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    }
}

void HumanPlayer::noMoves() {
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}