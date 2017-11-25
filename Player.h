#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <vector>

class Player {
public:
    /**
     * Constructor.
     * @param color The player color.
     */
    Player(int color);

    /**
     * Play a move.
     * @param moves The possible moves.
     * @param choice The player's choice.
     */
    virtual void playMove(std::vector<int> &moves, std::vector<int> &choice) = 0;

    /**
     * Wait for player response for no moves situation.
     */
    virtual void noMoves() = 0;

    /**
     * Get the player color.
     * @return 1 for X, 2 for O.
     */
    int getColor() const;

protected:
    int color;
};

#endif //EX2_PLAYER_H
