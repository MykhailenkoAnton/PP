#include "PPBall.h"
#include <iostream>


PPBall::PPBall()
{

    ballCoord.row = GameBall::START_ROW_COORD_BALL;
    ballCoord.column = GameBall::START_COLUMN_COORD_BALL;

    direction = eDirection::LEFT;
}

BallCoord PPBall::GetBallCoord() const
{
    return ballCoord;
}

void PPBall::SetBallCoord(BallCoord newCoord)
{
    ballCoord = newCoord;
}

void PPBall::Move()
{
    switch (GetBallDirection())
    {
    case eDirection::LEFT:
        MoveBallLEFT();
        break;
    case eDirection::RIGHT:
        MoveBallRIGHT();
        break;
    case eDirection::UPLEFT:
        MoveBallUPLEFT();
        break;
    case eDirection::UPRIGHT:
        MoveBallUPRIGHT();
        break;
    case eDirection::DOWNLEFT:
        MoveBallDOWNLEFT();
        break;
    case eDirection::DOWNRIGHT:
        MoveBallDOWNRIGHT();
        break;
    default:
        break;
    }
}

void PPBall::SetBallDirection(eDirection newDidection)
{
    direction = newDidection;
}

eDirection PPBall::GetBallDirection()
{
    return direction;
}

void PPBall::MoveBallRIGHT()
{
    ballCoord.column += 1;
    direction = eDirection::RIGHT;
}

void PPBall::MoveBallLEFT()
{
    ballCoord.column -= 1;
    direction = eDirection::LEFT;
}

void PPBall::MoveBallUPRIGHT()
{
    ballCoord.row -= 1;
    ballCoord.column += 1;
    direction = eDirection::UPRIGHT;
}

void PPBall::MoveBallUPLEFT()
{
    ballCoord.row -= 1;
    ballCoord.column -= 1;
    direction = eDirection::UPLEFT;
}

void PPBall::MoveBallDOWNRIGHT()
{
    ballCoord.row += 1;
    ballCoord.column += 1;
    direction = eDirection::DOWNRIGHT;
}

void PPBall::MoveBallDOWNLEFT()
{
    ballCoord.row += 1;
    ballCoord.column -= 1;
    direction = eDirection::DOWNLEFT;
}
