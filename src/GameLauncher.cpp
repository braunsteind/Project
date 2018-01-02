#include "GameLauncher.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "OnlineHumanPlayer.h"
#include "RemotePlayer.h"
#include "RegularRules.h"
#include "ConsoleDisplay.h"
#include "ConfigurationFileHandler.h"

GameLauncher::GameLauncher() {
    const int size = 8;
    board = new Board(size);
    rules = new RegularRules();
    display = new ConsoleDisplay();
    Mode playerMode = display->runMenu();
    switch (playerMode) {
        case Human:
            player1 = new HumanPlayer(Black, *board, rules, display);
            player2 = new HumanPlayer(White, *board, rules, display);
            break;
        case Computer:
            player1 = new HumanPlayer(Black, *board, rules, display);
            player2 = new ComputerPlayer(White, *board, rules, display);
            break;
        case Remote:
            ConfigurationFileHandler handler;
            handler.readConfigurationFile();
            int port = handler.getPortFromFile();
            const char *serverIP = handler.getIPFromFile();
            player1 = new OnlineHumanPlayer(Black, *board, rules, display, serverIP, port);
            //send command to server.
            ((OnlineHumanPlayer *) player1)->sendCommand();
            int socket = ((OnlineHumanPlayer *) player1)->getClientSocket();
            player2 = new RemotePlayer(White, *board, rules, display, serverIP, port, socket);
            Color player1Color = ((OnlineHumanPlayer *) player1)->getColorFromServer();
            player1->setColor(player1Color);
            Color player2Color;
            if (player1Color == Black) {
                player2Color = White;
            } else {
                player2Color = Black;
            }
            player2->setColor(player2Color);
            break;
    }
}

GameLauncher::~GameLauncher() {
    delete rules;
    delete player1;
    delete player2;
    delete display;
    delete board;
}

Rules *GameLauncher::getRules() const {
    return rules;
}

Display *GameLauncher::getDisplay() const {
    return display;
}

Board *GameLauncher::getBoard() const {
    return board;
}

Player *GameLauncher::getPlayer1() const {
    return player1;
}

Player *GameLauncher::getPlayer2() const {
    return player2;
}