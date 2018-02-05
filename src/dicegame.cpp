//
// Created by mato on 31.1.2018.
//
#include "../src/dicegame.h"
#include <random>
#include <iostream>

unsigned char Dice::getNumOfDice() {
    return numOfDice;
}

void Dice::setNumOfDice(const unsigned char newNumOfDice) {
    numOfDice = newNumOfDice;
}

const u32* Dice::rollDice(const u8 numOfDiceToBeThrew)
{
    for(unsigned char i = 0; i < MAX_NUM_OF_DICE; i++)
    {
        if(i < numOfDiceToBeThrew && i < numOfDice) {
            std::random_device rd; // obtain a random number from hardware
            std::mt19937 eng(rd()); // seed the generator
            std::uniform_int_distribution<> distr(1, 6); // define the range
            threw[i] = distr(eng);
        }
        else
        {
            threw[i] = 0;
        }
    }

    return threw;
}

u32 Dice::getPoints(const u32* const diceTable, const unsigned char len) const
{
    u32 numOfNumbers[6] = {0, 0, 0, 0, 0, 0};
    countNumOfSames(diceTable, len, numOfNumbers);
    return countPoint(numOfNumbers);
}

u32 Dice::countPoint(const u32* const numOfNumbers) const {
    u32 points = 0;

    if (numOfNumbers[0] >= 1)
    {
        points = static_cast<unsigned int>(numOfNumbers[0] >= 3 ? numOfNumbers[0] * 1000 - 2000 : numOfNumbers[0] * 100);
    }

    if(numOfNumbers[4] >= 1 && numOfNumbers[4] < 3)
    {
        points += numOfNumbers[4] * 50;
    }

    for(u8 i = 1; i < 6; i++)
    {
        if(numOfNumbers[i] >= 3)
        {
            points += numOfNumbers[i] * 100 * (i + 1) - (i + 1) * 200;
        }
    }
    return points;
}

void Dice::countNumOfSames(const u32* const roll, u8 len, u32* numOfNumbers) const
{
    for(u8 i = 0; i < len; i++)
    {
        if(roll[i] >= 1 && roll[i] <= 6)
        {
            numOfNumbers[(roll[i] - 1)]++;
        }
    }
}

bool Dice::isValid(const u32* const userChoice, u8 numOfDiceOfUserChoice) const
{
    u8 numOfNumbers[6] = {0, 0, 0, 0, 0, 0};

    for(u8 i = 0; i < numOfDiceOfUserChoice; i++)
    {
        if(userChoice[i] < 1 || userChoice[i] > 6)
        {
            return false;
        }
        else
        {
            numOfNumbers[(userChoice[i] - 1)]++;
        }
    }

    for(u8 i = 0; i < 6; i++)
    {
        if(numOfNumbers[i] < 3 && numOfNumbers[i] > 0)
        {
            if(i != 0 && i != 4)
            {
                return false;
            }
        }
    }

    return true;
}

void Dice::printRoll(const u32 *roll, const u8 len) const
{
    std::cout << "Roll: ";
    for (u8 i = 0; i < len; ++i)
    {
        std::cout << roll[i];
        if(i < (len - 1))
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

