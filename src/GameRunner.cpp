
#include "GameRunner.h"

GameRunner::GameRunner(Board &board, Player *player1, Player *player2, Rules *rules, Display *display) : board(board),
                                                                                                         player1(player1),
                                                                                                         player2(player2),
                                                                                                         rules(rules),
                                                                                                         display(display) {}

void GameRunner::run() {
    vector<int> playedMove;
    //play while at least one player can.
    while (player1->canPlay() || player2->canPlay()) {
        //play with player1.
        player1->playMove();
        //play with player2.
        player2->playMove();
    }
    //print the board.
    display->showBoard(board);
    //check for winner.
    Color winner = rules->winner(board);
    display->announceWinner(winner);
}