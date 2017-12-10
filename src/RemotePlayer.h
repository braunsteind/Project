#ifndef EX2_REMOTEPLAYER_H
#define EX2_REMOTEPLAYER_H

#include "Player.h"
#include <iostream>
#include <limits>
#include <unistd.h>

class RemotePlayer : public Player {
public:
    RemotePlayer(Color color, Board &board, Rules *rules, Display *display, const char *serverIP, int serverPort,
                 int clientSocket);

    virtual Point playMove();

    virtual void endPlay() const;

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};

#endif //EX2_REMOTEPLAYER_H