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
     * @return The chosen point. If couldn't play return -2, -2.
     */
    virtual Point playMove() = 0;

    /**
     * Check if the player can play.
     * @return True if can play, false if can't.
     */
    virtual bool canPlay() const;

    /**
     * End playing.
     */
    virtual void endPlay() const = 0;

    /**
     * Get the player color.
     * @return The player color.
     */
    Color getColor() const;

    /**
     * Set the color of the player.
     * @param newColor The new color.
     */
    void setColor(Color newColor);

protected:
    Color color;
    Board &board;
    Rules *rules;
    Display *display;
};

#endif //EX2_PLAYER_H