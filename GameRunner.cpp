//
// Daniel Braunstein 312510167.
//

#include "GameRunner.h"

GameRunner::GameRunner(Board &board, Player *player1, Player *player2, Rules *rules, Display *display) : board(board),
                                                                                                         player1(player1),
                                                                                                         player2(player2),
                                                                                                         rules(rules),
                                                                                                         display(display) {}

void GameRunner::run() {
    std::vector<int> moves;
    std::vector<int> choice;
    //play while at least one player can.
    while (canPlay(player1->getColor()) == 1 || canPlay(player2->getColor()) == 1) {
        //show board.
        display->showBoard(board);
        //get player1 possible moves.
        rules->whereCanPut(board, player1->getColor(), moves);
        //if no moves for player1.
        if (moves.size() <= 0) {
            display->noMoves(player1->getColor());
            player1->noMoves();
        } else {
            //show moves.
            display->showMoves(player1->getColor(), moves);
            //get player move.
            player1->playMove(moves, choice);
            //check the move.
            checkInput(player1, moves, choice);
            //play move.
            board.put(player1->getColor(), choice[0], choice[1]);
            //clear vectors.
            moves.clear();
            choice.clear();
        }
        //get player2 possible moves.
        rules->whereCanPut(board, player2->getColor(), moves);
        //if no moves for player2.
        if (moves.size() <= 0) {
            //get player1 possible moves.
            moves.clear();
            rules->whereCanPut(board, player1->getColor(), moves);
            //if game not ended.
            if (moves.size() > 0) {
                //show board.
                display->showBoard(board);
                display->noMoves(player2->getColor());
                player2->noMoves();
            }
        } else {
            //show board.
            display->showBoard(board);
            //show moves.
            display->showMoves(player2->getColor(), moves);
            //get player move.
            player2->playMove(moves, choice);
            //check the move.
            checkInput(player2, moves, choice);
            //play move.
            board.put(player2->getColor(), choice[0], choice[1]);
            //clear vectors.
            moves.clear();
            choice.clear();
        }
    }
    //print the board.
    display->showBoard(board);
    //check for winner.
    int winner = rules->winner(board);
    display->announceWinner(winner);
}

void GameRunner::checkInput(Player *player, std::vector<int> &moves, std::vector<int> &choice) const {
    while (true) {
        //loop on the vector.
        for (int i = 0; i < moves.size(); i = i + 2) {
            //if choice is ok, return.
            if (moves[i] == choice[0] && moves[i + 1] == choice[1]) {
                return;
            }
        }
        //if the choice isn't valid.
        display->invalidInput();
        //get new choice.
        choice.clear();
        player->playMove(moves, choice);
    }
}

int GameRunner::canPlay(int color) const {
    std::vector<int> moves;
    //check where the player can put.
    rules->whereCanPut(board, color, moves);
    //if can't play.
    if (moves.size() <= 0) {
        return 0;
    }
    return 1;
}