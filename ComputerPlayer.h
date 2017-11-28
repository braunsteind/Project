#ifndef EX2_COMPUTERPLAYER_H
#define EX2_COMPUTERPLAYER_H

#include "Player.h"

class ComputerPlayer : public Player {
public:
    ComputerPlayer(Color color, Board &board, Rules *rules, Display *display);

    virtual void playMove();
};

#endif //EX2_COMPUTERPLAYER_H