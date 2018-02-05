//
// Created by mato on 3.2.2018.
//

#ifndef NOPPAPELI_PLAYER_H
#define NOPPAPELI_PLAYER_H

#include "commonConstants.h"
#include "dicegame.h"
#include <string>

class Player
{
public:
    Player() {}
    virtual ~Player() {}

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &newName) {
        Player::name = newName;
    }

private:
    std::string name;
};


#endif //NOPPAPELI_PLAYER_H
