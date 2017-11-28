#include "Rules.h"

int Rules::winner(const Board &board) const {
    const int playerOne = 1;
    const int playerTwo = 2;
    const int tie = 0;
    int player1Score = getScore(playerOne, board);
    int player2Score = getScore(playerTwo, board);
    //if player1 wins.
    if (player1Score > player2Score) {
        return playerOne;
    } else if (player2Score > player1Score) { //if player 2 wins.
        return playerTwo;
    }
    //tie.
    return tie;
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