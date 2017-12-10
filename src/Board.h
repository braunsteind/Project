#ifndef EX2_BOARD_H
#define EX2_BOARD_H

#include "Point.h"

enum Color {
    Empty, Black, White
};

/**
 * The game board.
 */
class Board {
public:
    /**
     * Constructor.
     * @param size The board size.
     */
    Board(int size);

    /**
     * Copy constructor.
     * @param board The object.
     */
    Board(const Board &board);

    /**
     * Destructor.
     */
    ~Board();

    /**
     * Get the board size.
     * @return The board size.
     */
    int getSize() const;

    /**
     * Get the square in row i and column j.
     * @param i The row.
     * @param j The column.
     * @return The square.
     */
    Color getSquare(int i, int j) const;

    /**
     * Change the color between two points.
     * @param player The player color.
     * @param a The row.
     * @param b The column.
     */
    void put(Color player, int a, int b);

    /**
     * Equals override.
     * @param board The other board.
     * @return True if euqals, false if not.
     */
    bool operator==(const Board &board) const;

    Point getLastPut() const;

private:
    //the board size.
    int size;
    Point lastPut;
    //represents the players.
    Color **arr;

    /**
     * Swap between two ints.
     * @param a first int.
     * @param b second int.
     */
    void swap(int &a, int &b) const;

    /**
     * Flip all the squares between two points.
     * @param player The player to flip to.
     * @param i1 Row of square1.
     * @param j1 Column of square1.
     * @param i2 Row of square2.
     * @param j2 Column of square2.
     */
    void flipBetween(Color player, int i1, int j1, int i2, int j2);
};

#endif //EX2_BOARD_H