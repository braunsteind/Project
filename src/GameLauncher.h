#ifndef EX2_GAMELAUNCHER_H
#define EX2_GAMELAUNCHER_H

#include "Rules.h"
#include "Display.h"
#include "Player.h"

class GameLauncher {
public:
    /**
     * Constructor.
     */
    GameLauncher();
    /**
     * Destructor.
     */
    virtual ~GameLauncher();
    /**
     * Get rules
     * @return The rules.
     */
    Rules *getRules() const;
    /**
     * Get display.
     * @return The display.
     */
    Display *getDisplay() const;
    /**
     * Get board.
     * @return The board.
     */
    Board *getBoard() const;
    /**
     * Get player1.
     * @return Player1.
     */
    Player *getPlayer1() const;
    /**
     * Get player2.
     * @return Player2.
     */
    Player *getPlayer2() const;

private:
    Rules *rules;
    Display *display;
    Board *board;
    Player *player1;
    Player *player2;
};

#endif //EX2_GAMELAUNCHER_H