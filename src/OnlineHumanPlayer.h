#ifndef EX2_ONLINEHUMANPLAYER_H
#define EX2_ONLINEHUMANPLAYER_H

#include "HumanPlayer.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <cstdlib>

#define DATA_LENGTH 50

class OnlineHumanPlayer : public HumanPlayer {
public:
    OnlineHumanPlayer(Color color, Board &board, Rules *rules, Display *display, const char *serverIP, int serverPort);

    virtual Point playMove();

    /**
     * Connect the player to server.
     */
    void connectToServer();

    /**
     * Get client socket.
     * @return The client Socket.
     */
    int getClientSocket();

    virtual void endPlay() const;

    /**
     * Get the player color from the server.
     * @return The player color.
     */
    Color getColorFromServer();

    /**
     * Send command to server.
     */
    void sendCommand();

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;

    /**
     * Send the move to the server.
     * @param row The row.
     * @param col The col.
     */
    void sendMove(int row, int col);

    /**
     * Excute the command.
     * @param command The command.
     * @param run True if need to go back to get another command.
     */
    void executeCommand(string command, bool *run);
};

#endif //EX2_ONLINEHUMANPLAYER_H