#include "OnlineHumanPlayer.h"

OnlineHumanPlayer::OnlineHumanPlayer(Color color, Board &board, Rules *rules, Display *display, const char *serverIP,
                                     int serverPort) : HumanPlayer(color, board, rules, display), serverIP(serverIP),
                                                       serverPort(serverPort), clientSocket(0) {
    connectToServer();
    display->waitingForOtherPlayer();
}

Point OnlineHumanPlayer::playMove() {
    const int noMove = -2;
    //get played move.
    Point played = HumanPlayer::playMove();
    //send the played move to the other player.
    sendMove(played.getRow(), played.getColumn());
    return played;
}

void OnlineHumanPlayer::connectToServer() {
    // Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
    // Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }
    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *) &address, sizeof address, AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }
    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *) &address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *) &serverAddress.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    // htons converts values between host and network byte orders
    serverAddress.sin_port = htons(serverPort);
    // Establish a connection with the TCP server
    if (connect(clientSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    //announce player that he is connected.
    display->connectedToServer();
}

void OnlineHumanPlayer::sendMove(int row, int col) {
    //Write the move to the socket
    int n = write(clientSocket, &row, sizeof(row));
    if (n == -1) {
        throw "Error writing row to socket";
    }
    n = write(clientSocket, &col, sizeof(col));
    if (n == -1) {
        throw "Error writing col to socket";
    }
}

int OnlineHumanPlayer::getClientSocket() {
    return clientSocket;
}

Color OnlineHumanPlayer::getColorFromServer() {
    int n;
    char number;
    //read the player number.
    n = read(clientSocket, &number, sizeof(number));
    if (n == -1) {
        throw "Error reading the color";
    }
    if (n == 0) {
        throw "Player disconnected";
    }
    //if the color is black.
    if (number == '1') {
        return Black;
    } else if (number == '2') {
        return White;
    }
    throw "Error reading the color";
}

void OnlineHumanPlayer::endPlay() const {
    //end play consts.
    int row = -1;
    int col = -1;
    int n = write(clientSocket, &row, sizeof(row));
    if (n == -1) {
        throw "Error writing end play to socket";
    }
    n = write(clientSocket, &col, sizeof(col));
    if (n == -1) {
        throw "Error writing end play to socket";
    }
}