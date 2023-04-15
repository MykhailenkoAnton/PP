#include "Player.h"
#include "../../Utils.h"

#include "../Timer.h"

#include <iostream>


Player::Player()
{
    for (int i = 0; i < 5; i++)
    {
        playerCoord.row[i] = 10 + i;
        playerCoord.column[i] = 10;
    }

    oldPlayerCoord = playerCoord;
}

void Player::moveUP()
{
    if(IsPossiblePlayerToMoveUP())
    {
        TimerMS * Timer = TimerMS::GetInstance();
        Timer->StartTime();

        action = eAction::UP;
        for (int i = 0; i < PlayerI::PLAYER_SIZE; i++)
        {
            playerCoord.row[i] -= 1;
        }
    }
}

void Player::moveDOWN()
{
    if(IsPossiblePlayerToMoveDOWN())
    {
        TimerMS * Timer = TimerMS::GetInstance();
        Timer->StartTime();

        action = eAction::DOWN;
        for (int i = 0; i < PlayerI::PLAYER_SIZE; i++)
        {
            playerCoord.row[i] += 1;
        };
    }
}

bool Player::IsPossiblePlayerToMoveDOWN()
{
    if(playerCoord.row[PlayerI::PLAYER_LAST_INDEX] + 1 == FieldE::END_FIELD_ROW) 
    {
        return false;
    }
    return true;
}

bool Player::IsPossiblePlayerToMoveUP()
{
    if(playerCoord.row[PlayerI::PLAYER_START_INDEX] - 1 == FieldE::START_FIELD_ROW) 
    {
        return false;
    }
    return true;
}