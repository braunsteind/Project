#ifndef EX2_RULES_H
#define EX2_RULES_H

#include "Board.h"

class Rules {
public:
    /**
     * Check where the player can put.
     * @param board The game board.
     * @param color The player color.
     * @return The answer vector of possible moves.
     */
    virtual vector<int> whereCanPut(const Board &board, Color color) const = 0;

    /**
     * Tell who the winner.
     * @return The winner color.
     */
    Color winner(const Board &board) const;
    /**
     * Get the player score.
     * @param player The player.
     * @param board The game board.
     * @return The score of the player.
     */
    virtual int getScore(int player, const Board &board) const;
};

#endif //EX2_RULES_H
