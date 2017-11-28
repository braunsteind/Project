//
// Created by shlomi on 11/28/17.
//

#include <gtest/gtest.h>
#include "../src/RegularRules.h"


TEST(RegularRules, scoreTest) {
    //EXPECT_EQ(1,1);
    Board b(8);
    RegularRules r;
    EXPECT_EQ(r.getScore(Black,b),r.getScore(White,b));
    b.put(Black,0,0);
    EXPECT_EQ(r.getScore(Black,b),3);  //THIS SHOULD WORK
    EXPECT_EQ(r.getScore(Black,b),4);  //THIS SHOULD NOT WORK, BUT IT WORKS


}

TEST(RegularRules, winnerTest) {
    Board b(8);
    RegularRules r;
    //EXPECT_EQ(r.winner(b),0);

}