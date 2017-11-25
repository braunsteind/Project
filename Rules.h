#ifndef EX2_RULES_H
#define EX2_RULES_H

#include "Board.h"

class Rules {
public:
    /**
     * Check where the player can put.
     * @param board The game board.
     * @param color The player color.
     * @param moves The answer vector.
     */
    virtual void whereCanPut(const Board &board, int color, std::vector<int> &moves) const = 0;

    /**
     * Tell who the winner.
     * @return 1 - player1, 2 - player2, 0 - tie.
     */
    int winner(const Board &board);
};

#endif //EX2_RULES_H
