#pragma once
#include "../../Utils.h"

struct PlayerCoord
{
    int row[5];
    int column[5];
};

class Player
{
public:

    Player();
    
    const PlayerCoord & GetPlayerCoord() const {return playerCoord;} 
    
    void moveUP();
    void moveDOWN();
    void moveRIGHT();
    void moveLEFT();
    
protected:
    PlayerCoord playerCoord;
};