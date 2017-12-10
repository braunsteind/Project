#include <climits>
#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(Color color, Board &board, Rules *rules, Display *display) : Player(color, board, rules,
                                                                                                   display) {}

Point ComputerPlayer::playMove() {
    Color enemy;
    if (color == Black) {
        enemy = White;
    } else {
        enemy = Black;
    }
    vector<Point> moves, opponentMoves;
    int computerBestScore = INT_MAX, computerBestMove = -1;
    //get all possible moves.
    moves = rules->whereCanPut(board, color);
    //loop on the computer moves.
    for (int i = 0; i < moves.size(); i++) {
        //copy to board to temp board.
        Board computerTempBoard(board);
        //play move on the temp board.
        computerTempBoard.put(color, moves[i].getRow(), moves[i].getColumn());
        //check where the opponent can put.
        opponentMoves = rules->whereCanPut(computerTempBoard, enemy);
        //set the opponent best score to min.
        int opponentBestScore = INT_MIN;
        //loop on the opponent moves.
        for (int j = 0; j < opponentMoves.size(); j++) {
            //copy the board to temp board.
            Board opponentTempBoard(computerTempBoard);
            //play move on the temp board.
            opponentTempBoard.put(enemy, opponentMoves[j].getRow(), opponentMoves[j].getColumn());
            //calculate the deference between the opponent score and the computer score.
            int deference = rules->getScore(enemy, opponentTempBoard) - rules->getScore(color, opponentTempBoard);
            //if the deference is bigger than the opponent's best score.
            if (deference > opponentBestScore) {
                //update the opponent's best score.
                opponentBestScore = deference;
            }
        }
        //if the opponent best score is lower than the computer best score.
        if (opponentBestScore < computerBestScore) {
            //update the best score.
            computerBestScore = opponentBestScore;
            //update the computer best move.
            computerBestMove = i;
        }
    }
    //if no moves.
    if (computerBestMove == -1) {
        display->announceNoMove(color);
        return Point(-2, -2);
    }
    //get the best move.
    Point choice(moves[computerBestMove]);
    //return the computer move.
    display->announceMove(color, choice.getRow() + 1, choice.getColumn() + 1);
    return choice;
}

void ComputerPlayer::endPlay() const {}