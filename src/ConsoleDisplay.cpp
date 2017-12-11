#include "ConsoleDisplay.h"

void ConsoleDisplay::announceWinner(Color winner) const {
    switch (winner) {
        case Black:
            cout << endl << "X IS THE WINNER" << endl;
            break;
        case White:
            cout << endl << "O IS THE WINNER" << endl;
            break;
        default:
            cout << endl << "TIE" << endl;
    }
}

void ConsoleDisplay::showBoard(Board &board) const {
    cout << endl << "Current board:" << endl;
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
                case Empty:
                    cout << "  | ";
                    break;
                case Black:
                    cout << "X | ";
                    break;
                case White:
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

void ConsoleDisplay::noMoves(Color color) const {
    if (color == Black) {
        cout << "X: It's your move." << endl;
    } else if (color == White) {
        cout << "O: It's your move." << endl;
    } else {
        return;
    }
    cout << "No possible moves. Play passes back to the other player. Press any key to continue." << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

void ConsoleDisplay::showMoves(Color player, vector<Point> &moves) const {
    if (player == Black) {
        cout << "X: It's your move." << endl << "Your possible moves: ";
    } else if (player == White) {
        cout << "O: It's your move." << endl << "Your possible moves: ";
    } else {
        return;
    }
    //print the possible moves.
    for (int i = 0; i < moves.size() - 1; i++) {
        cout << "(" << moves[i].getRow() + 1 << "," << moves[i].getColumn() + 1 << "), ";
    }
    //print last possible move.
    cout << "(" << moves[moves.size() - 1].getRow() + 1 << "," << moves[moves.size() - 1].getColumn() + 1 << ")"
         << endl;
    cout << endl << "Please enter your move (row col): ";
}

void ConsoleDisplay::invalidInput() const {
    cout << "Invalid input, please enter your move (row col): ";
}

void ConsoleDisplay::announceMove(Color player, int row, int column) const {
    if (player == Black) {
        cout << "X played (" << row << "," << column << ")" << endl;
    } else if (player == White) {
        cout << "O played (" << row << "," << column << ")" << endl;
    }
}

void ConsoleDisplay::announceNoMove(Color player) const {
    if (player == Black) {
        cout << "X has no moves" << endl;
    } else if (player == White) {
        cout << "O has no moves" << endl;
    }
}

Mode ConsoleDisplay::runMenu() const {
    int choice = 0;
    //printing menu
    cout << "Please select one of the options:" << endl;
    cout << "Press 1 for playing against local player" << endl;
    cout << "Press 2 for playing against computer player" << endl;
    cout << "Press 3 for playing against a remote player" << endl;
    //while the input is not valid.
    while (choice != Computer && choice != Human && choice != Remote) {
        //get input.
        cin >> choice;
        //if the input is not valid.
        if (choice != Computer && choice != Human && choice != Remote) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //print illegal input message.
            cout << "Illegal choice." << endl;
            cout
                    << "Press 1 for playing against the computer, 2 for playing against other player and 3 for remote player"
                    << endl;
        }
    }
    //return the wanted player
    return static_cast<Mode>(choice);
}

void ConsoleDisplay::connectedToServer() const {
    cout << "Connected to server" << endl;
}

void ConsoleDisplay::waitingForOtherPlayer() const {
    cout << "Waiting for other player to join..." << endl;
}

void ConsoleDisplay::waitingForOtherPlayerMove() const {
    cout << "Waiting for other player's move..." << endl;
}