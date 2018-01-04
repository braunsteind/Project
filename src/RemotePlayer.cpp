#include "RemotePlayer.h"

RemotePlayer::RemotePlayer(Color color, Board &board, Rules *rules, Display *display, const char *serverIP,
                           int serverPort, int clientSocket) : Player(color, board, rules, display), serverIP(serverIP),
                                                               serverPort(serverPort), clientSocket(clientSocket) {}

Point RemotePlayer::playMove() {
    const int gameEnded = -1, noMove = -2, serverEnded = -3;
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
    //check if server ended.
    if (row == serverEnded) {
        //end the game.
        display->serverEnded();
        rules->engGame();
        //return any point.
        return Point(0, 0);
    }
    n = read(clientSocket, &col, sizeof(row));
    if (n == -1) {
        throw "Error reading the move";
    }
    if (n == 0) {
        throw "Player disconnected";
    }

    Point choice(row, col);
    if (row != gameEnded || col != gameEnded) { //if game not ended.
        //if no move.
        if (row == noMove && col == noMove) {
            display->announceNoMove(color);
        } else {
            //announce the move.
            display->announceMove(color, row + 1, col + 1);
        }
    }
    return choice;
}

void RemotePlayer::endPlay() const {}