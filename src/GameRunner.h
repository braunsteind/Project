#ifndef EX2_GAMERUNNER_H
#define EX2_GAMERUNNER_H

#include "Board.h"
#include "Player.h"
#include "Rules.h"
#include "Display.h"
#include <iostream>
#include <limits>

using namespace std;

/**
 * The class that will run the game.
 */
class GameRunner {
public:
    /**
     * Constructor.
     * @param board The game board.
     * @param player1 The first player.
     * @param player2 The second player.
     * @param rules The game rules.
     * @param display The display way of the game.
     */
    GameRunner(Board &board, Player *player1, Player *player2, Rules *rules, Display *display);

    /**
     * Run the game.
     */
    void run();

private:
    Board &board;
    Player *player1;
    Player *player2;
    Rules *rules;
    Display *display;
};

#endif //EX2_GAMERUNNER_H