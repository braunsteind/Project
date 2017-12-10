#include "Board.h"

Board::Board(int size) : size(size) {
    this->lastPut = Point(-3, -3);
    //set the board.
    arr = new Color *[size];
    for (int i = 0; i < size; i++) {
        arr[i] = new Color[size];
    }
    //set the board to empty.
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = Empty;
        }
    }
    //set starting position.
    arr[(size / 2) - 1][size / 2] = Black;
    arr[size / 2][(size / 2) - 1] = Black;
    arr[(size / 2) - 1][(size / 2) - 1] = White;
    arr[size / 2][size / 2] = White;
}

Board::Board(const Board &board) {
    //copy the size;
    size = board.getSize();
    lastPut = board.getLastPut();
    arr = new Color *[size];
    for (int i = 0; i < size; i++) {
        arr[i] = new Color[size];
    }
    //copy the arr.
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = board.getSquare(i, j);
        }
    }
}

Board::~Board() {
    for (int i = 0; i < size; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int Board::getSize() const {
    return size;
}

Point Board::getLastPut() const {
    return lastPut;
}

Color Board::getSquare(int i, int j) const {
    return arr[i][j];
}

void Board::put(Color player, int a, int b) {
    const int noMove = -2;
    //if point not on board.
    if (a < 0 || a >= size || b < 0 || b >= size) {
        //if didn't put anything
        lastPut.setPoint(noMove, noMove);
        return;
    }
    //put.
    arr[a][b] = player;
    //update lastPut.
    lastPut.setPoint(a, b);
    int i, j, enemy = 3 - player;
    //up.
    i = a - 1;
    j = b;
    //if there is an enemy.
    if (i >= 0 && arr[i][j] == enemy) {
        //go to the last enemy.
        while (i >= 0 && arr[i][j] == enemy) {
            i--;
        }
        //if should flip.
        if (i >= 0 && arr[i][j] == player) {
            flipBetween(player, a, b, i, j);
        }
    }
    //up right.
    i = a - 1;
    j = b + 1;
    //if there is an enemy.
    if (i >= 0 && j < size && arr[i][j] == enemy) {
        //go to the last enemy.
        while (i >= 0 && j < size && arr[i][j] == enemy) {
            i--;
            j++;
        }
        //if can put.
        if (i >= 0 && j < size && arr[i][j] == player) {
            flipBetween(player, a, b, i, j);
        }
    }
    //right.
    i = a;
    j = b + 1;
    //if there is an enemy.
    if (j < size && arr[i][j] == enemy) {
        //go to the last enemy.
        while (j < size && arr[i][j] == enemy) {
            j++;
        }
        //if can put.
        if (j < size && arr[i][j] == player) {
            flipBetween(player, a, b, i, j);
        }
    }
    //down right.
    i = a + 1;
    j = b + 1;
    //if there is an enemy.
    if (i < size && j < size && arr[i][j] == enemy) {
        //go to the last enemy.
        while (i < size && j < size && arr[i][j] == enemy) {
            i++;
            j++;
        }
        //if can put.
        if (i < size && j < size && arr[i][j] == player) {
            flipBetween(player, a, b, i, j);
        }
    }
    //down.
    i = a + 1;
    j = b;
    //if there is an enemy.
    if (i < size && arr[i][j] == enemy) {
        //go to the last enemy.
        while (i < size && arr[i][j] == enemy) {
            i++;
        }
        //if can put.
        if (i < size && arr[i][j] == player) {
            flipBetween(player, a, b, i, j);
        }
    }
    //down left.
    i = a + 1;
    j = b - 1;
    //if there is an enemy.
    if (i < size && j >= 0 && arr[i][j] == enemy) {
        //go to the last enemy.
        while (i < size && j >= 0 && arr[i][j] == enemy) {
            i++;
            j--;
        }
        //if can put.
        if (i < size && j >= 0 && arr[i][j] == player) {
            flipBetween(player, a, b, i, j);
        }
    }
    //left.
    i = a;
    j = b - 1;
    //if there is an enemy.
    if (j >= 0 && arr[i][j] == enemy) {
        //go to the last enemy.
        while (j >= 0 && arr[i][j] == enemy) {
            j--;
        }
        //if can put.
        if (j >= 0 && arr[i][j] == player) {
            flipBetween(player, a, b, i, j);
        }
    }
    //up left.
    i = a - 1;
    j = b - 1;
    //if there is an enemy.
    if (i >= 0 && j >= 0 && arr[i][j] == enemy) {
        //go to the last enemy.
        while (i >= 0 && j >= 0 && arr[i][j] == enemy) {
            i--;
            j--;
        }
        //if can put.
        if (i >= 0 && j >= 0 && arr[i][j] == player) {
            flipBetween(player, a, b, i, j);
        }
    }
}

void Board::flipBetween(Color player, int i1, int j1, int i2, int j2) {
    //if same row.
    if (i1 == i2) {
        //if j1 is bigger.
        if (j2 < j1) {
            //swap.
            swap(j1, j2);
        }
        //while can still move right.
        while (j1 < j2) {
            //flip and move.
            arr[i1][j1] = player;
            j1++;
        }
        //if same column.
    } else if (j1 == j2) {
        //if i1 is bigger.
        if (i2 < i1) {
            swap(i1, i2);
        }
        //while can still move down.
        while (i1 < i2) {
            //flip and move.
            arr[i1][j1] = player;
            i1++;
        }
    } else {
        //make sure to move down.
        if (i2 < i1) {
            swap(i1, i2);
            swap(j1, j2);
        }
        //if going right.
        if (j1 < j2) {
            //while can move right.
            while (j1 < j2) {
                //flip and move.
                arr[i1][j1] = player;
                i1++;
                j1++;
            }
            //if going left
        } else {
            //while can move left.
            while (j2 < j1) {
                //flip and move.
                arr[i1][j1] = player;
                i1++;
                j1--;
            }
        }
    }
}

bool Board::operator==(const Board &board) const {
    //check the size is the same.
    if (size != board.getSize()) {
        return false;
    }
    //check the matrix are the same.
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] != board.getSquare(i, j)) {
                return false;
            }
        }
    }
    return true;
}

void Board::swap(int &a, int &b) const {
    int temp = a;
    a = b;
    b = temp;
}