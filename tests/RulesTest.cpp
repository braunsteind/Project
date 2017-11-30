#include <gtest/gtest.h>
#include "../src/RegularRules.h"

TEST(RegularRules, ScoreTest) {
    Board board(8);
    RegularRules rules;
    EXPECT_EQ(rules.getScore(Black, board), rules.getScore(White, board));
    board.put(Black, 0, 0);
    EXPECT_EQ(rules.getScore(Black, board), 3);
    EXPECT_EQ(rules.getScore(White, board), 2);
}

TEST(RegularRules, WinnerTest) {
    Board board(8);
    RegularRules rules;
    EXPECT_EQ(rules.winner(board), 0);
    board.put(Black, 1, 1);
    EXPECT_EQ(rules.winner(board), Black);
    board.put(White, 2, 2);
    EXPECT_EQ(rules.winner(board), 0);
    board.put(White, 5, 7);
    EXPECT_EQ(rules.winner(board), White);
}

TEST(RegularRules, WhereCanPut) {
    //check if can play.
    Board a(8);
    RegularRules rules;
    vector<Point> moves, answer;
    //the possible moves.
    answer.insert(answer.begin(), {Point(5, 4), Point(3, 2), Point(2, 3), Point(4, 5)});
    //the moves we get from function.
    moves = rules.whereCanPut(a, Black);
    EXPECT_EQ(answer, moves);
    //check if can't play.
    Board c(8);
    for (int i = 0; i < c.getSize(); i++) {
        for (int j = 0; j < c.getSize(); j++) {
            c.put(Black, i, j);
        }
    }
    answer.clear();
    moves = rules.whereCanPut(c, White);
    EXPECT_EQ(answer, moves);

    //if have only one possible move.
    c.put(Empty, 7, 7);
    c.put(White, 5, 7);
    answer.insert(answer.begin(), {Point(7, 7)});
    moves = rules.whereCanPut(c, White);
    EXPECT_EQ(answer, moves);
}