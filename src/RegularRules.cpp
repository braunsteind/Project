#include "RegularRules.h"

vector<int> RegularRules::whereCanPut(const Board &board, Color color) const {
    vector<int> moves;
    //loop on each square
    for (int i = 0; i < board.getSize(); i++) {
        for (int j = 0; j < board.getSize(); j++) {
            //if the square belong to the player.
            if (board.getSquare(i, j) == color) {
                //get the results for the square.
                checkSurrounding(board, color, i, j, moves);
            }
        }
    }
    removeDouble(moves);
    return moves;
}

void RegularRules::checkSurrounding(const Board &board, int player, int a, int b, std::vector<int> &moves) const {
    int size = board.getSize();
    int i, j, enemy = 3 - player;
    //up.
    i = a - 1;
    j = b;
    //if there is an enemy.
    if (i >= 0 && board.getSquare(i, j) == enemy) {
        //go to the last enemy.
        while (i >= 0 && board.getSquare(i, j) == enemy) {
            i--;
        }
        //if can put.
        if (i >= 0 && board.getSquare(i, j) == 0) {
            moves.push_back(i);
            moves.push_back(j);
        }
    }
    //up right.
    i = a - 1;
    j = b + 1;
    //if there is an enemy.
    if (i >= 0 && j < size && board.getSquare(i, j) == enemy) {
        //go to the last enemy.
        while (i >= 0 && j < size && board.getSquare(i, j) == enemy) {
            i--;
            j++;
        }
        //if can put.
        if (i >= 0 && j < size && board.getSquare(i, j) == 0) {
            moves.push_back(i);
            moves.push_back(j);
        }
    }
    //right.
    i = a;
    j = b + 1;
    //if there is an enemy.
    if (j < size && board.getSquare(i, j) == enemy) {
        //go to the last enemy.
        while (j < size && board.getSquare(i, j) == enemy) {
            j++;
        }
        //if can put.
        if (j < size && board.getSquare(i, j) == 0) {
            moves.push_back(i);
            moves.push_back(j);
        }
    }
    //down right.
    i = a + 1;
    j = b + 1;
    //if there is an enemy.
    if (i < size && j < size && board.getSquare(i, j) == enemy) {
        //go to the last enemy.
        while (i < size && j < size && board.getSquare(i, j) == enemy) {
            i++;
            j++;
        }
        //if can put.
        if (i < size && j < size && board.getSquare(i, j) == 0) {
            moves.push_back(i);
            moves.push_back(j);
        }
    }
    //down.
    i = a + 1;
    j = b;
    //if there is an enemy.
    if (i < size && board.getSquare(i, j) == enemy) {
        //go to the last enemy.
        while (i < size && board.getSquare(i, j) == enemy) {
            i++;
        }
        //if can put.
        if (i < size && board.getSquare(i, j) == 0) {
            moves.push_back(i);
            moves.push_back(j);
        }
    }
    //down left.
    i = a + 1;
    j = b - 1;
    //if there is an enemy.
    if (i < size && j >= 0 && board.getSquare(i, j) == enemy) {
        //go to the last enemy.
        while (i < size && j >= 0 && board.getSquare(i, j) == enemy) {
            i++;
            j--;
        }
        //if can put.
        if (i < size && j >= 0 && board.getSquare(i, j) == 0) {
            moves.push_back(i);
            moves.push_back(j);
        }
    }
    //left.
    i = a;
    j = b - 1;
    //if there is an enemy.
    if (j >= 0 && board.getSquare(i, j) == enemy) {
        //go to the last enemy.
        while (j >= 0 && board.getSquare(i, j) == enemy) {
            j--;
        }
        //if can put.
        if (j >= 0 && board.getSquare(i, j) == 0) {
            moves.push_back(i);
            moves.push_back(j);
        }
    }
    //up left.
    i = a - 1;
    j = b - 1;
    //if there is an enemy.
    if (i >= 0 && j >= 0 && board.getSquare(i, j) == enemy) {
        //go to the last enemy.
        while (i >= 0 && j >= 0 && board.getSquare(i, j) == enemy) {
            i--;
            j--;
        }
        //if can put.
        if (i >= 0 && j >= 0 && board.getSquare(i, j) == 0) {
            moves.push_back(i);
            moves.push_back(j);
        }
    }
}

void RegularRules::removeDouble(std::vector<int> &vec) const {
    //loop on the squares.
    for (int i = 0; i < vec.size(); i = i + 2) {
        //for every square, compare the other squares.
        for (int j = i + 2; j < vec.size(); j = j + 2) {
            //if the squares are the same.
            if (vec[i] == vec[j] && vec[i + 1] == vec[j + 1]) {
                //remove the square.
                vec.erase(vec.begin() + j);
                vec.erase(vec.begin() + j);
                j = j - 2;
            }
        }
    }
}