#include "RegularRules.h"

vector<Point> RegularRules::whereCanPut(const Board &board, Color color) const {
    vector<Point> moves;
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

void RegularRules::checkSurrounding(const Board &board, Color player, int a, int b, vector<Point> &moves) const {
    const int getEnemy = 3;
    int size = board.getSize();
    int i, j, enemy = getEnemy - player;
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
            moves.push_back(Point(i, j));
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
            moves.push_back(Point(i, j));
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
            moves.push_back(Point(i, j));
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
            moves.push_back(Point(i, j));
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
            moves.push_back(Point(i, j));
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
            moves.push_back(Point(i, j));
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
            moves.push_back(Point(i, j));
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
            moves.push_back(Point(i, j));
        }
    }
}

void RegularRules::removeDouble(vector<Point> &vec) const {
    //loop on the squares.
    for (int i = 0; i < vec.size(); i++) {
        //for every point, compare the other points.
        for (int j = i + 1; j < vec.size(); j++) {
            //if the points are the same.
            if (vec[i] == vec[j]) {
                //remove the point.
                vec.erase(vec.begin() + j);
                j--;
            }
        }
    }
}