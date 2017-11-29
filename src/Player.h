#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <vector>
#include "Board.h"
#include "Rules.h"
#include "Display.h"

class Player {
public:
    /**
     * Constructor.
     * @param color The player color.
     * @param board The game board.
     * @param rules The game rules.
     * @param display The display format.
     */
    Player(Color color, Board &board, Rules *rules, Display *display);

    /**
     * Play one move with the player.
     */
    virtual void playMove() = 0;

    /**
     * Check if the player can play.
     * @return 1 if can play, 0 if can't.
     */
    int canPlay() const;

    /**
     * Get the player color.
     * @return The player color.
     */
    Color getColor() const;

protected:
    Color color;
    Board &board;
    Rules *rules;
    Display *display;
};

#endif //EX2_PLAYER_H