#include "RemotePlayer.h"

RemotePlayer::RemotePlayer(Color color, Board &board, Rules *rules, Display *display, const char *serverIP,
                           int serverPort, int clientSocket) : Player(color, board, rules, display), serverIP(serverIP),
                                                               serverPort(serverPort), clientSocket(clientSocket) {}

Point RemotePlayer::playMove() {
    int n, row, col;
    n = read(clientSocket, &row, sizeof(row));
    if (n == -1) {
        cout << "Error reading the move" << endl;
        //return;
    }
    if (n == 0) {
        cout << "Player disconnected" << endl;
        //return;
    }
    n = read(clientSocket, &col, sizeof(row));
    if (n == -1) {
        cout << "Error reading the move" << endl;
        //return;
    }
    if (n == 0) {
        cout << "Player disconnected" << endl;
        //return;
    }
    Point choice(row, col);
    return choice;
}