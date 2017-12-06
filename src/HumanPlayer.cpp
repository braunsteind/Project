#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(Color color, Board &board, Rules *rules, Display *display) : Player(color, board, rules,
                                                                                             display) {}

Point HumanPlayer::playMove() {
    vector<Point> moves;
    //show board.
    display->showBoard(board);
    //get the player's possible moves.
    moves = rules->whereCanPut(board, color);
    //if no moves for player1.
    if (moves.empty()) {
        display->noMoves(color);
        return Point();
    }
    //show moves.
    display->showMoves(color, moves);
    //get the move.
    Point choice = getInput(moves);
    return choice;
}

Point HumanPlayer::getInput(vector<Point> &moves) const {
    Point p(-1, -1);
    int row, col;
    while (true) {
        //get row and col.
        cin >> row >> col;
        //if the player didn't input a number.
        if (!cin) {
            //reset fail bit.
            cin.clear();
            //skip bad input
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            //row and col -1 in order to use in the vector.
            row--;
            col--;
            //set the point.
            p.setRow(row);
            p.setColumn(col);
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        }
        //loop on the possible moves vector.
        for (int i = 0; i < moves.size(); i++) {
            //if choice is ok, return the point.
            if (moves[i] == p) {
                return p;
            }
        }
        //if the choice isn't valid.
        display->invalidInput();
    }
}