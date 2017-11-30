#include "Board.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "GameRunner.h"
#include "RegularRules.h"
#include "ConsoleDisplay.h"
#include "Point.h"

using namespace std;

int main() {
    const int size = 8;
    Rules *rules = new RegularRules();
    Board board(size);
    Display *display = new ConsoleDisplay();
    Player *player1 = new HumanPlayer(Black, board, rules, display);
    Player *player2;
    Mode playerMode = display->runMenu();
    //if computer player mode.
    if (playerMode == Computer) {
        player2 = new ComputerPlayer(White, board, rules, display);
    } else if (playerMode == Human) { //if human player mode.
        player2 = new HumanPlayer(White, board, rules, display);
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