#include <gtest/gtest.h>
#include "../src/HumanPlayer.h"
#include "../src/RegularRules.h"
#include "../src/ConsoleDisplay.h"

TEST(HumanPlayer, CanMoveTest) {
    RegularRules rules;
    ConsoleDisplay display;
    Board board1(2);
    HumanPlayer player1(Black, board1, &rules, &display);
    HumanPlayer player2(White, board1, &rules, &display);
    //check can't move.
    EXPECT_FALSE(player1.canPlay());
    EXPECT_FALSE(player2.canPlay());
    //check can play move.
    Board board2(10);
    HumanPlayer player3(Black, board2, &rules, &display);
    HumanPlayer player4(White, board2, &rules, &display);
    EXPECT_TRUE(player3.canPlay());
    EXPECT_TRUE(player4.canPlay());
}