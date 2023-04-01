#include "Field.h"

#include <thread>
#include <windows.h>
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
    for (int i = 0; i < FieldE::ROW; i++)
    {
        for (int j = 0; j < FieldE::COLUMN; j++)
        {
            field[i][j] = FieldE::EMPTY;

            if(i == 0 || i == FieldE::ROW - 1 || j == 0 || j == FieldE::COLUMN - 1)
            {
                field[i][j] = FieldE::BOARDER;
            }
        }
    }
    
}

void Field::ShowField()
{
    system("cls");
    
    for (int row = 0; row < FieldE::ROW; row++)
    {
        for (int columm = 0; columm < FieldE::COLUMN; columm++)
        {
            std::cout << field[row][columm];
        }
        std::cout << std::endl;
    }
    Sleep(50);
}

void Field::ShowPlayerOnField()
{
    ClearFieldElement(FieldE::PLAYER);

    const auto PlayerCoord = player.GetPlayerCoord();
    for (int i = 0; i < PlayerI::PLAYER_SIZE; i++)
    {
        field[PlayerCoord.row[i]][PlayerCoord.column[i]] = FieldE::PLAYER;
    }
    
}

void Field::ShowBallOnField()
{
    ClearFieldElement(FieldE::BALL);

    const auto BallCoord = ball.GetBallCoord();
    field[BallCoord.row][BallCoord.column] = FieldE::BALL;
}

void Field::PlayerMove(eAction ActionMove)
{
    switch (ActionMove)
    {
    case eAction::UP:
        if(IsPossiblePlayerToMoveUP())
        {
            player.moveUP();
        }
        break;
    case eAction::DOWN:
        if(IsPossiblePlayerToMoveDOWN())
        {
            player.moveDOWN();
        }
        break;
    case eAction::LEFT:
        if(IsPossiblePlayerToMoveLEFT())
        {
            player.moveLEFT();
        }
        break;
    case eAction::RIGHT:
        if(IsPossiblePlayerToMoveRIGHT())
        {
            player.moveRIGHT();   
        }
        break;

    default:
        break;
    }

}

bool Field::IsPossiblePlayerToMoveUP()
{
    const auto PlayerCoord = player.GetPlayerCoord();
    if(PlayerCoord.row[PlayerI::PLAYER_START_INDEX] - 1 == FieldE::START_FIELD_ROW) 
    {
        return false;
    }
    
    return true;
}

bool Field::IsPossiblePlayerToMoveDOWN()
{
    const auto PlayerCoord = player.GetPlayerCoord();
    if(PlayerCoord.row[PlayerI::PLAYER_LAST_INDEX] + 1 == FieldE::END_FIELD_ROW) 
    {
        return false;
    }
    
    return true;
}

bool Field::IsPossiblePlayerToMoveRIGHT()
{
    const auto PlayerCoord = player.GetPlayerCoord();
    for (int i = 0; i < PlayerI::PLAYER_SIZE; i++)
    {
        if(PlayerCoord.column[i] + 1 == FieldE::END_FIELD_COLUMN)
        {
            return false;
        }
    }
    
    return true;
}

bool Field::IsPossiblePlayerToMoveLEFT()
{
    const auto PlayerCoord = player.GetPlayerCoord();
    for (int i = 0; i < PlayerI::PLAYER_SIZE; i++)
    {
        if(PlayerCoord.column[i] - 1 == FieldE::START_FIELD_COLUMN)
        {
            return false;
        }
    }
    
    return true;
}

void Field::ClearFieldElement(char body)
{
    for (int row = 0; row < FieldE::ROW; row++)
    {
        for (int columm = 0; columm < FieldE::COLUMN; columm++)
        {
            if(field[row][columm] == body)
            {
                field[row][columm] = FieldE::EMPTY;
            }
        }
    }
}