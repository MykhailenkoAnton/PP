#include "PlayerAI.h"

PlayerAI::PlayerAI()
{
    for (int i = 0; i < 5; i++)
    {
        playerCoord.row[i] = 10 + i;
        playerCoord.column[i] = 90;
    }

}