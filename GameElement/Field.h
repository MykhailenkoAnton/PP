#pragma once
#include "Player.h"

const int ROW = 22;
const int COLUMN = 100;
class Field
{
private:
    char field[ROW][COLUMN];
    void FillField();

    Player player;

public:
    Field();
    ~Field();
    void ShowField();

    void ShowPlayerOnField();
    void MovePlayerUP();
    void MovePlayerDOWN();
    void MovePlayerRIGHT();
    void MovePlayerLEFT();

private:
    void ClearPlayer();
    void ClearPlayerFromScreen();

    bool bIsMoved = false;
    bool IsPossiblePlayerToMoveUP();
    bool IsPossiblePlayerToMoveDOWN();
    bool IsPossiblePlayerToMoveRIGHT();
    bool IsPossiblePlayerToMoveLEFT();
};