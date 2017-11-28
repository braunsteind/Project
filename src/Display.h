#ifndef EX2_DISPLAY_H
#define EX2_DISPLAY_H

#include "Board.h"

class Display {
public:
    /**
     * Announce the winner.
     * @param winner 1 for player1, 2 for player2, any other number for tie.
     */
    virtual void announceWinner(int winner) const = 0;

    /**
     * Show the board.
     * @param board The game board.
     */
    virtual void showBoard(Board &board) const = 0;

    /**
     * Announce that there is no possible moves.
     * @param color The player color.
     */
    virtual void noMoves(int color) const = 0;

    /**
     * Show the player possible moves.
     * @param player 1 for player1, other for player2.
     * @param moves The player possible moves.
     */
    virtual void showMoves(int player, std::vector<int> &moves) const = 0;

    /**
     * Announce the input is invalid.
     */
    virtual void invalidInput() const = 0;

    /**
     * Announce the move.
     * @param player The player.
     * @param row The row that played.
     * @param column The column that played.
     */
    virtual void announceMove(int player, int row, int column) const = 0;

    /**
     * Running the menu before game starts.
     */
    virtual int runMenu() const = 0;
};

#endif //EX2_DISPLAY_H
