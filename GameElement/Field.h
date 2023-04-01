#pragma once
#include "Player.h"
#include "PPBall.h"

class Field
{
public:
    Field();
    ~Field();
    void ShowField();
    void ShowPlayerOnField();
    void ShowBallOnField();
    void PlayerMove(eAction ActionMove);
    void ClearFieldElement(char body);

private:

    bool IsPossiblePlayerToMoveUP();
    bool IsPossiblePlayerToMoveDOWN();
    bool IsPossiblePlayerToMoveRIGHT();
    bool IsPossiblePlayerToMoveLEFT();

    char field[FieldE::ROW][FieldE::COLUMN];
    void FillField();

    Player player;
    PPBall ball;
};