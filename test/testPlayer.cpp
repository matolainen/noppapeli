//
// Created by mato on 4.2.2018.
//

#include <limits.h>
#include <gtest/gtest.h>
#include "../src/Player.h"

class TestPlayer : public::testing::Test
{
protected:
    virtual void SetUp() {}
    virtual void TearDown() {}
    Player player;
};

TEST_F(TestPlayer, testSetAndGetName)
{
    player.setName("Jaakko");
    EXPECT_EQ("Jaakko", player.getName());
}

TEST_F(TestPlayer, playerRollDiceAndGetPoints)
{
    player.setName("Noppamies");
    auto roll = player.rollDice(MAX_NUM_OF_DICE);
    EXPECT_TRUE(player.getPoints(roll, MAX_NUM_OF_DICE));
}

TEST_F(TestPlayer, playerRollDiceAndFailsToGetPoints)
{

}