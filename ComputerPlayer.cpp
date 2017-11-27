#include <climits>
#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(int color, Board &board, Rules *rules, Display *display) : Player(color, board, rules,
                                                                                                 display) {}

void ComputerPlayer::playMove() {
    vector<int> moves, choice, opponentMoves;
    int computerBestScore = INT_MAX, computerBestMove;
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
            opponentTempBoard.put(3 - color, opponentMoves[j], opponentMoves[j + 1]);
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
    //play the computer best move.
    board.put(color, moves[computerBestMove], moves[computerBestMove + 1]);
}