//
// Created by mato on 31.1.2018.
//

#include <limits.h>
#include <gtest/gtest.h>
#include "../src/dicegame.h"

class TestDiceGame : public::testing::Test
{
protected:
    virtual void SetUp() {}
    virtual void TearDown() {}
    Dice dice;
};

TEST_F(TestDiceGame, testSetNumOfDice)
{
    dice.setNumOfDice(5);
    EXPECT_EQ(5, dice.getNumOfDice());
}

TEST_F(TestDiceGame, testThrowDice)
{
    dice.setNumOfDice(MAX_NUM_OF_DICE);
    auto diceTable = dice.rollDice(dice.getNumOfDice());
    bool isValidThrow = true;

    for(unsigned char i = 0; i < dice.getNumOfDice(); i++)
    {
        if(diceTable[i] < 1 || diceTable[i] > 6) {
            isValidThrow = false;
        }

    }
    EXPECT_TRUE(isValidThrow);
}

TEST_F(TestDiceGame, testCountPoints)
{
    dice.setNumOfDice(MAX_NUM_OF_DICE);
    const u32 diceTable[MAX_NUM_OF_DICE] = {1, 1, 1, 1, 4, 5, 6, 2, 5, 5};
    const u32 points = dice.getPoints(diceTable, dice.getNumOfDice());
    EXPECT_EQ(2500, points);
}

TEST_F(TestDiceGame, testAllowedChoices)
{
    dice.setNumOfDice(MAX_NUM_OF_DICE);
    u8 numOfOfDiceOfUserChoice = 7;
    u32 userChoices[numOfOfDiceOfUserChoice] = {1, 1, 1, 1, 5, 5, 5};
    EXPECT_TRUE(dice.isValid(userChoices, numOfOfDiceOfUserChoice));

    userChoices[0] = 2;
    EXPECT_FALSE(dice.isValid(userChoices, numOfOfDiceOfUserChoice));

    userChoices[0] = 7;
    EXPECT_FALSE(dice.isValid(userChoices, numOfOfDiceOfUserChoice));

    u32 userChoices2[numOfOfDiceOfUserChoice] = {2, 2, 3, 3, 4, 6, 6};
    EXPECT_FALSE(dice.isValid(userChoices2, numOfOfDiceOfUserChoice));
}

TEST_F(TestDiceGame, testRound)
{
    dice.setNumOfDice(MAX_NUM_OF_DICE);
    u8 numOfOfDiceOfUserChoice = 7;
    u32 userChoices[numOfOfDiceOfUserChoice] = {1, 1, 1, 1, 5, 5, 5};
    u32 points = dice.getPoints(userChoices, numOfOfDiceOfUserChoice);
    u32 userChoices2[3] = {2, 2, 2};
    points += dice.getPoints(userChoices2, 3);
    points += dice.getPoints(userChoices, numOfOfDiceOfUserChoice);
    EXPECT_EQ(5200, points);
}

TEST_F(TestDiceGame, testShowRolledDice)
{
    dice.setNumOfDice(MAX_NUM_OF_DICE);
    auto roll = dice.rollDice(dice.getNumOfDice());

    dice.printRoll(roll, dice.getNumOfDice());
    SUCCEED();
}
