#ifndef PLAYER_H_
#define PLAYER_H_

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
    
    PlayerCoord GetPlayerCoord() const {return playerCoord;} 
    
    void moveUP();
    void moveDOWN();

    void SetPlayerAction(eAction newAction) {action = newAction;}
    eAction GetPlayerAction() const {return action;}

    void AddScore() {Score++;}
    int GetScore() {return Score;}


protected:

    bool bIsPlayerMove = false;

    bool IsPossiblePlayerToMoveDOWN();
    bool IsPossiblePlayerToMoveUP();

    PlayerCoord playerCoord;
    PlayerCoord oldPlayerCoord;
    
    eAction action = eAction::NONE;

    int Score = 0;

};

#endif //PLAYER_H_