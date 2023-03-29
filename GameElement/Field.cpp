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
    system("cls");
    ClearPlayerFromScreen();
    
    for (int row = 0; row < ROW; row++)
    {
        for (int columm = 0; columm < COLUMN; columm++)
        {
            std::cout << field[row][columm];
        }
        std::cout << std::endl;
    }
    // Sleep(50);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
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
    player.moveUP();
    bIsMoved = true;
}

void Field::MovePlayerDOWN()
{
    player.moveDOWN();
    bIsMoved = true;
}

void Field::MovePlayerRIGHT()
{
    player.moveRIGHT();
    bIsMoved = true;
}

void Field::MovePlayerLEFT()
{
    player.moveLEFT();
    bIsMoved = true;
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