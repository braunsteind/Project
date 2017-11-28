#ifndef EX2_REGULARRULES_H
#define EX2_REGULARRULES_H

#include "Board.h"
#include "Rules.h"

class RegularRules : public Rules {
public:
    /**
     * Check where the player can put on the board.
     * @param board The game board.
     * @param color The player color.
     * @param moves The answer vector.
     */
    virtual void whereCanPut(const Board &board, int color, std::vector<int> &moves) const;

private:
    /**
     * Check the square area.
     * @param board The game board.
     * @param player The player color.
     * @param row The row.
     * @param col The column.
     * @param moves The answer vector.
     */
    void checkSurrounding(const Board &board, int player, int row, int col, std::vector<int> &moves) const;

    /**
     * remove duplication of same square.
     * @param vec The vector to remove from.
     */
    void removeDouble(std::vector<int> &vec) const;
};

#endif //EX2_REGULARRULES_H