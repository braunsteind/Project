#include "RemotePlayer.h"

RemotePlayer::RemotePlayer(Color color, Board &board, Rules *rules, Display *display, const char *serverIP,
                           int serverPort, int clientSocket) : Player(color, board, rules, display), serverIP(serverIP),
                                                               serverPort(serverPort), clientSocket(clientSocket) {}

Point RemotePlayer::playMove() {
    int n, row, col;
    //wait for move.
    display->waitingForOtherPlayerMove();
    n = read(clientSocket, &row, sizeof(row));
    if (n == -1) {
        throw "Error reading the move";
    }
    if (n == 0) {
        throw "Player disconnected";
    }
    n = read(clientSocket, &col, sizeof(row));
    if (n == -1) {
        throw "Error reading the move";
    }
    if (n == 0) {
        throw "Player disconnected";
    }
    Point choice(row, col);
    //if game not ended.
    if (row != -1 || col != -1) {
        //if no move.
        if (row == -2 && col == -2) {
            display->announceNoMove(color);
        } else {
            //announce the move.
            display->announceMove(color, row + 1, col + 1);
        }
    }
    return choice;
}

void RemotePlayer::endPlay() const {}