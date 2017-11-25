#include "Rules.h"

int Rules::winner(const Board &board) {
    int countPlayer1 = 0;
    int countPlayer2 = 0;
    //loop on the board.
    for (int i = 0; i < board.getSize(); i++) {
        for (int j = 0; j < board.getSize(); j++) {
            //count the disks.
            if (board.getSquare(i, j) == 1) {
                countPlayer1++;
            } else if (board.getSquare(i, j) == 2) {
                countPlayer2++;
            }
        }
    }
    //if player1 wins.
    if (countPlayer1 > countPlayer2) {
        return 1;
    } else if (countPlayer2 > countPlayer1) {
        return 2;
    }
    return 0;
}