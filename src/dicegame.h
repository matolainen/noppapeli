//
// Created by mato on 31.1.2018.
//

#ifndef NOPPAPELI_DICEGAME_H
#define NOPPAPELI_DICEGAME_H

#include "commonConstants.h"

class Dice
{
public:
    Dice()
    {
        init();
    }

    void init() {
        numOfDice = 0;
        for(unsigned char i = 0; i < MAX_NUM_OF_DICE; i++)
        {
            threw[i] = 0xFF;
        }
    }

    unsigned char getNumOfDice();
    void setNumOfDice(const u8 newNumOfDice);
    const u32* rollDice(const unsigned char numOfDiceToBeThrew);
    u32 getPoints(const u32* const diceTable, const unsigned char len) const;
    bool isValid(const u32* const userChoice, u8 numOfDiceOfUserChoice) const;
    void printRoll(const u32* roll, const u8 len) const;
private:
    void countNumOfSames(const u32* const roll, u8 len, u32* numOfNumbers) const;
    unsigned char numOfDice;
    u32 threw[MAX_NUM_OF_DICE];
    u32 countPoint(const u32* numOfNumbers) const;
};

#endif //NOPPAPELI_DICEGAME_H
