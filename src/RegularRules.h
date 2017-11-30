#ifndef EX2_REGULARRULES_H
#define EX2_REGULARRULES_H

#include "Board.h"
#include "Rules.h"

class RegularRules : public Rules {
public:
    virtual vector<Point> whereCanPut(const Board &board, Color color) const;

private:
    /**
     * Check the square area.
     * @param board The game board.
     * @param player The player color.
     * @param row The row.
     * @param col The column.
     * @param moves The answer vector.
     */
    void checkSurrounding(const Board &board, Color player, int row, int col, vector<Point> &moves) const;

    /**
     * remove duplication of same square.
     * @param vec The vector to remove from.
     */
    void removeDouble(vector<Point> &vec) const;
};

#endif //EX2_REGULARRULES_H