#include "Field.h"
#include "../../Utils.h"
#include "thread"
#include "windows.h"
#include <iostream>


Field::Field()
{
    FillField();
}

Field::~Field()
{
}

void Field::FillField()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            field[i][j] = ' ';

            if(i == 0 || i == ROW - 1 || j == 0 || j == COLUMN - 1)
            {
                field[i][j] = 'X';
            }
        }
    }
    
}

void Field::ShowField()
{
    ClearPlayerFromScreen();
    system("cls");
    
    for (int row = 0; row < ROW; row++)
    {
        for (int columm = 0; columm < COLUMN; columm++)
        {
            std::cout << field[row][columm];
        }
        std::cout << std::endl;
    }
    Sleep(25);
}

void Field::ShowPlayerOnField()
{
    ClearPlayerFromScreen();

    const auto PlayerCoord = player.GetPlayerCoord();
    for (int i = 0; i < PLAYER_SIZE; i++)
    {
        field[PlayerCoord.row[i]][PlayerCoord.column[i]] = 'P';
    }
    
}

void Field::MovePlayerUP()
{
    if(IsPossiblePlayerToMoveUP())
    {
        player.moveUP();
        bIsMoved = true;
    }
}

void Field::MovePlayerDOWN()
{
    if(IsPossiblePlayerToMoveDOWN())
    {
        player.moveDOWN();
        bIsMoved = true;
    }
}

void Field::MovePlayerRIGHT()
{
    if(IsPossiblePlayerToMoveRIGHT())
    {
        player.moveRIGHT();   
        bIsMoved = true;
    }
}

void Field::MovePlayerLEFT()
{
    if(IsPossiblePlayerToMoveLEFT())
    {
        player.moveLEFT();
        bIsMoved = true;
    }
}

void Field::ClearPlayer()
{
    for (int row = 0; row < ROW; row++)
    {
        for (int columm = 0; columm < COLUMN; columm++)
        {
            if(field[row][columm] == 'P')
            {
                field[row][columm] = ' ';
            }
        }
    }
}

void Field::ClearPlayerFromScreen()
{
    if(bIsMoved)
    {
        ClearPlayer();
        bIsMoved = false;
    }
}

bool Field::IsPossiblePlayerToMoveUP()
{
    const auto PlayerCoord = player.GetPlayerCoord();
    if(PlayerCoord.row[0] - 1 == 0) 
    {
        return false;
    }
    
    return true;
}

bool Field::IsPossiblePlayerToMoveDOWN()
{
    const auto PlayerCoord = player.GetPlayerCoord();
    if(PlayerCoord.row[4] + 1 == 21) 
    {
        return false;
    }
    
    return true;
}

bool Field::IsPossiblePlayerToMoveRIGHT()
{
    const auto PlayerCoord = player.GetPlayerCoord();
    for (int i = 0; i < PLAYER_SIZE; i++)
    {
        if(PlayerCoord.column[i] + 1 == 99)
        {
            return false;
        }
    }
    
    return true;
}

bool Field::IsPossiblePlayerToMoveLEFT()
{
    const auto PlayerCoord = player.GetPlayerCoord();
    for (int i = 0; i < PLAYER_SIZE; i++)
    {
        if(PlayerCoord.column[i] - 1 == 0)
        {
            return false;
        }
    }
    
    return true;
}