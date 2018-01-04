#ifndef EX2_RULES_H
#define EX2_RULES_H

#include <vector>
#include "Board.h"
#include "Point.h"

using namespace std;

class Rules {
public:
    /**
     * Constructor.
     */
    Rules();

    /**
     * Check where the player can put.
     * @param board The game board.
     * @param color The player color.
     * @return The answer vector of possible moves.
     */
    virtual vector<Point> whereCanPut(const Board &board, Color color) const = 0;

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
    virtual int getScore(Color player, const Board &board) const;

    /**
     * End the game.
     */
    virtual void engGame();

    /**
     * Check if game ended before finished.
     * @return The end game bool.
     */
    virtual bool getEndGame();

protected:
    bool endGame;
};

#endif //EX2_RULES_H