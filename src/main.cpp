#include "Board.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "GameRunner.h"
#include "RegularRules.h"
#include "ConsoleDisplay.h"
#include "OnlineHumanPlayer.h"
#include "RemotePlayer.h"

using namespace std;

int main() {
    const int size = 8;
    Rules *rules = new RegularRules();
    Board board(size);
    Display *display = new ConsoleDisplay();
    Player *player1;
    Player *player2;
    Mode playerMode = display->runMenu();
    //if computer player mode.
    if (playerMode == Human) {
        player1 = new HumanPlayer(Black, board, rules, display);
        player2 = new HumanPlayer(White, board, rules, display);
    } else if (playerMode == Computer) { //if human player mode.
        player1 = new HumanPlayer(Black, board, rules, display);
        player2 = new ComputerPlayer(White, board, rules, display);
    } else if (playerMode == Remote) {
        char *serverIP = "127.0.0.1";
        int port = 8000;
        player1 = new OnlineHumanPlayer(Black, board, rules, display, serverIP, port);
        OnlineHumanPlayer *tempPlayer = dynamic_cast<OnlineHumanPlayer *>(player1);
        int socket = tempPlayer->getClientSocket();
        player2 = new RemotePlayer(White, board, rules, display, serverIP, port, socket);
        Color player1Color = tempPlayer->getColorFromServer();
        player1->setColor(player1Color);
        Color player2Color;
        if (player1Color == Black) {
            player2Color = White;
        } else {
            player2Color = Black;
        }
        player2->setColor(player2Color);
    } else { //if illegal playerMode.
        return 0;
    }
    GameRunner game(board, player1, player2, rules, display);
    game.run();
    delete rules;
    delete player1;
    delete player2;
    delete display;
    return 0;
}