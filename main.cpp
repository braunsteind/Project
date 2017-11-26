#include "Board.h"
#include "HumanPlayer.h"
#include "GameRunner.h"
#include "RegularRules.h"
#include "ConsoleDisplay.h"

#define SIZE 8

int main() {
    Rules *rules = new RegularRules();
    Board board(SIZE);
    Display *display = new ConsoleDisplay();
    Player *player1 = new HumanPlayer(1, board, rules, display);
    Player *player2 = new HumanPlayer(2, board, rules, display);
    GameRunner game(board, player1, player2, rules, display);
    game.run();
    delete rules;
    delete player1;
    delete player2;
    delete display;
    return 0;
}