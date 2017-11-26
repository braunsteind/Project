#ifndef EX2_HUMANPLAYER_H
#define EX2_HUMANPLAYER_H

#include "Player.h"
#include <limits>
#include <iostream>

using namespace std;

class HumanPlayer : public Player {
public:
    HumanPlayer(int color, Board &board, Rules *rules, Display *display);

    virtual void playMove();

private:
    /**
     * Get the player input and check the input is valid.
     * @param moves The possible moves.
     * @param choice The player's choice.
     */
    void getInput(std::vector<int> &moves, std::vector<int> &choice) const;
};

#endif //EX2_HUMANPLAYER_H