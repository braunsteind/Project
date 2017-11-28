#include "Board.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "GameRunner.h"
#include "RegularRules.h"
#include "ConsoleDisplay.h"
#include <iostream>

#define SIZE 8
#define AI 1

using namespace std;

int main() {
    
    Rules *rules = new RegularRules();
    Board board(SIZE);
    Display *display = new ConsoleDisplay();
    Player *player1 = new HumanPlayer(Black, board, rules, display);
    Player *player2;
    int playerType = display->runMenu();
    if (playerType == AI) {
        player2 = new ComputerPlayer(White, board, rules, display);
    } else {
        player2 = new HumanPlayer(White, board, rules, display);
    }
    GameRunner game(board, player1, player2, rules, display);
    game.run();
    delete rules;
    delete player1;
    delete player2;
    delete display;
    return 0; 
    /*
    Board b(8);
    RegularRules r;
    b.put(Black,0,0);
    cout << "Black are: " << r.getScore(Black,b) << " White are: " << r.getScore(White, b);
    return 0; */
}