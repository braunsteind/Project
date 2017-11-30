#include "Rules.h"

Color Rules::winner(const Board &board) const {
    int player1Score = getScore(Black, board);
    int player2Score = getScore(White, board);
    //if player1 wins.
    if (player1Score > player2Score) {
        return Black;
    } else if (player2Score > player1Score) { //if player 2 wins.
        return White;
    }
    //tie.
    return Empty;
}

int Rules::getScore(Color player, const Board &board) const {
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