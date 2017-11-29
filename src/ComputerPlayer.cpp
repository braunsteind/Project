#include <climits>
#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(Color color, Board &board, Rules *rules, Display *display) : Player(color, board, rules,
                                                                                                   display) {}

vector<int> ComputerPlayer::playMove() {
    Color enemy;
    if (color == Black) {
        enemy = White;
    } else {
        enemy = Black;
    }
    vector<int> moves, choice, opponentMoves;
    int computerBestScore = INT_MAX, computerBestMove = -1;
    //get all possible moves.
    rules->whereCanPut(board, color, moves);
    //loop on the computer moves.
    for (int i = 0; i < moves.size(); i = i + 2) {
        //copy to board to temp board.
        Board computerTempBoard(board);
        //play move on the temp board.
        computerTempBoard.put(color, moves[i], moves[i + 1]);
        //check where the opponent can put.
        rules->whereCanPut(computerTempBoard, 3 - color, opponentMoves);
        //set the opponent best score to min.
        int opponentBestScore = INT_MIN;
        //loop on the opponent moves.
        for (int j = 0; j < opponentMoves.size(); j = j + 2) {
            //copy the board to temp board.
            Board opponentTempBoard(computerTempBoard);
            //play move on the temp board.
            opponentTempBoard.put(enemy, opponentMoves[j], opponentMoves[j + 1]);
            //calculate the deference between the opponent score and the computer score.
            int deference = rules->getScore(3 - color, opponentTempBoard) - rules->getScore(color, opponentTempBoard);
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
        return choice;
    }
    //get the best move.
    choice.push_back(moves[computerBestMove]);
    choice.push_back(moves[computerBestMove + 1]);
    //play the computer best move.
    board.put(color, choice[0], choice[1]);
    //return the computer move.
    display->announceMove(color, moves[computerBestMove] + 1, moves[computerBestMove + 1] + 1);
    return choice;
}