#ifndef EX2_HUMANPLAYER_H
#define EX2_HUMANPLAYER_H

#include "Player.h"
#include <limits>
#include <iostream>

using namespace std;

class HumanPlayer : public Player {
public:
    HumanPlayer(int color);

    virtual void playMove(std::vector<int> &moves, std::vector<int> &choice);

    virtual void noMoves();
};

#endif //EX2_HUMANPLAYER_H
