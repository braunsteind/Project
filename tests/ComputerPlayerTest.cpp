#include <gtest/gtest.h>
#include "../src/ComputerPlayer.h"
#include "../src/RegularRules.h"
#include "../src/ConsoleDisplay.h"

TEST(ComputerPlayer, PlayMoveTest) {
    Point choice, answer;
    RegularRules rules;
    ConsoleDisplay display;
    Board board(8);
    ComputerPlayer computerPlayer(White, board, &rules, &display);
    //play for the player.
    board.put(Black, 5, 4);
    //the computer move.
    choice = computerPlayer.playMove();
    board.put(White, choice.getRow(), choice.getColumn());
    //the right move.
    answer.setPoint(3, 5);
    EXPECT_EQ(answer, choice);
    //play for the player.
    board.put(Black, 2, 3);
    //the computer move.
    choice = computerPlayer.playMove();
    board.put(White, choice.getRow(), choice.getColumn());
    //the right move.
    answer.setPoint(6, 4);
    EXPECT_EQ(answer, choice);
    //play for the player.
    board.put(Black, 4, 5);
    //the computer move.
    choice = computerPlayer.playMove();
    board.put(White, choice.getRow(), choice.getColumn());
    //the right move.
    answer.setPoint(3, 2);
    EXPECT_EQ(answer, choice);
}

TEST(ComputerPlayer, CanMoveTest) {
    RegularRules rules;
    ConsoleDisplay display;
    Board board1(2);
    ComputerPlayer player1(Black, board1, &rules, &display);
    ComputerPlayer player2(White, board1, &rules, &display);
    //check can't move.
    EXPECT_FALSE(player1.canPlay());
    EXPECT_FALSE(player2.canPlay());
    //check can play move.
    Board board2(10);
    ComputerPlayer player3(Black, board2, &rules, &display);
    ComputerPlayer player4(White, board2, &rules, &display);
    EXPECT_TRUE(player3.canPlay());
    EXPECT_TRUE(player4.canPlay());
}