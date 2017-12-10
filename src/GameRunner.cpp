
#include "GameRunner.h"

GameRunner::GameRunner(Board &board, Player *player1, Player *player2, Rules *rules, Display *display) : board(board),
                                                                                                         player1(player1),
                                                                                                         player2(player2),
                                                                                                         rules(rules),
                                                                                                         display(display) {}

void GameRunner::run() {
    Point played;
    //play while at least one player can.
    while (player1->canPlay() || player2->canPlay()) {
        //make sure black play first.
        if (player1->getColor() == Black) {
            //play with player1.
            played = player1->playMove();
            board.put(player1->getColor(), played.getRow(), played.getColumn());
            //if game not over.
            if (player1->canPlay() || player2->canPlay()) {
                //play with player2.
                played = player2->playMove();
                board.put(player2->getColor(), played.getRow(), played.getColumn());
            }
        } else {
            //play with player2.
            played = player2->playMove();
            board.put(player2->getColor(), played.getRow(), played.getColumn());
            //if game not over.
            if (player1->canPlay() || player2->canPlay()) {
                //play with player1.
                played = player1->playMove();
                board.put(player1->getColor(), played.getRow(), played.getColumn());
            }
        }
    }
    player1->endPlay();
    //print the board.
    display->showBoard(board);
    //check for winner.
    Color winner = rules->winner(board);
    display->announceWinner(winner);
}