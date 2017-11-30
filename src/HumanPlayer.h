#ifndef EX2_HUMANPLAYER_H
#define EX2_HUMANPLAYER_H

#include "Player.h"
#include <limits>

using namespace std;

class HumanPlayer : public Player {
public:
    HumanPlayer(Color color, Board &board, Rules *rules, Display *display);

    virtual Point playMove();

private:
    /**
     * Get the player input and check the input is valid.
     * @param moves The possible moves.
     * @param choice The player's choice.
     */
    Point getInput(vector<Point> &moves) const;
};

#endif //EX2_HUMANPLAYER_H