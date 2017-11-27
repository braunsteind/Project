#include "Rules.h"

int Rules::winner(const Board &board) const {
    int player1Score = getScore(1, board);
    int player2Score = getScore(2, board);
    //if player1 wins.
    if (player1Score > player2Score) {
        return 1;
    } else if (player2Score > player1Score) { //if player 2 wins.
        return 2;
    }
    //tie.
    return 0;
}

int Rules::getScore(int player, const Board &board) const {
    int score = 0;
    //loop on the board.
    for (int i = 0; i < board.getSize(); i++) {
        for (int j = 0; j < board.getSize(); j++) {
            //count the disks.
            if (board.getSquare(i, j) == player) {
                score++;
            }
        }
    }
    return score;
}