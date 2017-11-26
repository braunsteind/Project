//
// Created by daniel on 11/11/17.
//

#include <limits>
#include "ConsoleDisplay.h"

void ConsoleDisplay::announceWinner(int winner) const {
    switch (winner) {
        case 0:
            cout << endl << "Tie" << endl;
            break;
        case 1:
            cout << endl << "X IS THE WINNER" << endl;
            break;
        case 2:
            cout << endl << "O IS THE WINNER" << endl;
            break;
        default:
            break;
    }
}

void ConsoleDisplay::showBoard(Board &board) const {
    cout << endl << "Current board:" << endl << endl;
    cout << " | ";
    for (int i = 1; i <= board.getSize(); i++) {
        cout << i << " | ";
    }
    cout << endl;
    cout << "--";
    for (int i = 0; i < board.getSize(); i++) {
        cout << "----";
    }
    cout << endl;
    //loop for the rows.
    for (int i = 0; i < board.getSize(); i++) {
        cout << i + 1 << "| ";
        //loop for the columns.
        for (int j = 0; j < board.getSize(); j++) {
            //check if the spot is marked.
            switch (board.getSquare(i, j)) {
                case 0:
                    cout << "  | ";
                    break;
                case 1:
                    cout << "X | ";
                    break;
                case 2:
                    cout << "O | ";
                    break;
                default:
                    break;
            }
        }
        cout << endl << "--";
        for (int k = 0; k < board.getSize(); k++) {
            cout << "----";
        }
        cout << endl;
    }
}

void ConsoleDisplay::noMoves(int color) const {
    if (color == 1) {
        cout << "X: It's your move." << endl;
    } else {
        cout << "O: It's your move." << endl;
    }
    cout << "No possible moves. Play passes back to the other player. Press any key to continue." << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

void ConsoleDisplay::showMoves(int player, std::vector<int> &moves) const {
    if (player == 1) {
        cout << "X: It's your move." << endl << "Your possible moves: ";
    } else {
        cout << "O: It's your move." << endl << "Your possible moves: ";
    }
    for (int i = 0; i < moves.size() - 2; i = i + 2) {
        cout << "(" << moves[i] + 1 << "," << moves[i + 1] + 1 << "), ";
    }
    //print last possible move.
    cout << "(" << moves[moves.size() - 2] + 1 << "," << moves[moves.size() - 1] + 1
         << ")" << endl;
    cout << endl << "Please enter your move (row col): ";
}

void ConsoleDisplay::invalidInput() const {
    cout << "Invalid input, please enter your move (row col): ";
}