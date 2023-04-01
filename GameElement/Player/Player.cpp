#include "Player.h"
#include "../../Utils.h"

#include <iostream>


Player::Player()
{
    for (int i = 0; i < 5; i++)
    {
        playerCoord.row[i] = 10 + i;
        playerCoord.column[i] = 20;
    }
}

void Player::moveUP()
{
    for (int i = 0; i < PlayerI::PLAYER_SIZE; i++)
    {
        playerCoord.row[i] -= 1;
    }
}

void Player::moveDOWN()
{
    for (int i = 0; i < PlayerI::PLAYER_SIZE; i++)
    {
        playerCoord.row[i] += 1;
    };
}

void Player::moveRIGHT()
{
    for (int i = 0; i < PlayerI::PLAYER_SIZE; i++)
    {
        playerCoord.column[i] += 1;
    }
    
}

void Player::moveLEFT()
{
    for (int i = 0; i < PlayerI::PLAYER_SIZE; i++)
    {
        playerCoord.column[i] -= 1;
    }
}