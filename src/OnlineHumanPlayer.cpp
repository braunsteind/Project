#include "OnlineHumanPlayer.h"

OnlineHumanPlayer::OnlineHumanPlayer(Color color, Board &board, Rules *rules, Display *display, const char *serverIP,
                                     int serverPort) : HumanPlayer(color, board, rules, display), serverIP(serverIP),
                                                       serverPort(serverPort), clientSocket(0) {
    connectToServer();
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
    cout << "writing to" << clientSocket << endl;
    cout << "row:" << row << endl;
    //Write the move to the socket
    int n = write(clientSocket, &row, sizeof(row));
    if (n == -1) {
        throw "Error writing row to socket";
    }
    cout << "col:" << col << endl;
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

void OnlineHumanPlayer::sendCommand() {
    bool run = true;
    while (run) {
        //show commands.
        display->showCommands();
        int dataLength = 0, twoWordsCommand = 0, spaceIndex = 0;
        vector<string> args;
        char data[DATA_LENGTH];
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.getline(data, sizeof(data));
        cout << "writing data to socket: " << clientSocket << endl;
        //send data to server.
        int n = write(clientSocket, &data, sizeof(data));
        if (n == -1) {
            throw "Error writing end play to socket";
        }
        //loop on the data from client.
        for (int i = 0; i < DATA_LENGTH; i++) {
            //update the length
            dataLength++;
            //check if the command ended and if it's one or two words.
            if (data[i] == '\0') {
                break;
            } else if (data[i] == ' ') {
                spaceIndex = i;
                twoWordsCommand = 1;
            }
        }
        //if one word command.
        if (twoWordsCommand == 0) {
            //create command.
            char command[dataLength];
            //copy the command.
            for (int i = 0; i < dataLength; i++) {
                command[i] = data[i];
            }
            //active command (args empty).
            executeCommand(string(command), &run);
        } else { //if two words command.
            char command[spaceIndex + 1];
            char name[dataLength - (spaceIndex + 1)];
            //copy the command.
            for (int i = 0; i < spaceIndex; i++) {
                command[i] = data[i];
            }
            command[spaceIndex] = '\0';
            //copy the name.
            for (int i = 0; i < dataLength - (spaceIndex + 1); i++) {
                name[i] = data[i + spaceIndex + 1];
            }
            //insert the room name to args.
            args.push_back(string(name));
            //active command.
            executeCommand(string(command), &run);
        }
    }
}

void OnlineHumanPlayer::executeCommand(string command, bool *run) {
    if (command.compare("start") == 0) {
        display->waitingForOtherPlayer();
        *run = false;
    } else if (command.compare("join") == 0) {
        *run = false;
    } else if (command.compare("list_games") == 0) {
        int n;
        vector<string> gamesList;
        char room[DATA_LENGTH];
        //while there are rooms to show.
        do {
            n = read(clientSocket, &room, sizeof(room));
            if (n == -1) {
                throw "Error reading the room";
            }
            if (n == 0) {
                throw "Disconnected";
            }
            gamesList.push_back(string(room));
        } while (string(room).compare("\0") != 0);
        //remove the empty room name.
        gamesList.erase(gamesList.end());
        display->showGamesList(gamesList);
    }
}