#include "Field.h"

#include "Timer.h"

// #include <thread>
#include <windows.h>
#include <iostream>
#include <time.h>
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

    std::cout << "============================ PLAYER SCROE >>>   " << player.GetScore() << "    " << AIPlayer.GetScore() << "   <<< BOT SCORE =============================" << std::endl; // change later

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

void Field::ShowAIPlayerOnField()
{
    ClearFieldElement(FieldE::AIPLAYER);

    const auto AIPlayerCoord = AIPlayer.GetPlayerCoord();
    for (int i = 0; i < PlayerI::PLAYER_SIZE; i++)
    {
        field[AIPlayerCoord.row[i]][AIPlayerCoord.column[i]] = FieldE::AIPLAYER;
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
        player.moveUP();
        // AIPlayer.moveUP();
        break;
    case eAction::DOWN:
        player.moveDOWN();
        // AIPlayer.moveDOWN();
        break;
    case eAction::NONE:
        player.SetPlayerAction(eAction::NONE);
        break;
    default:
        break;
    }

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


void Field::MoveBall()
{
    ball.Move();
    
    if(ball.GetBallCoord().column - 1 == FieldE::START_FIELD_COLUMN || ball.GetBallCoord().column == FieldE::END_FIELD_COLUMN)
    {
        ball.GetBallCoord().column - 1 == FieldE::START_FIELD_COLUMN ? AIPlayer.AddScore() : player.AddScore();
        MoveBallOnStartPlace();
    }

    if(ball.GetBallCoord().row - 1 == FieldE::START_FIELD_ROW || ball.GetBallCoord().row + 1 == FieldE::END_FIELD_ROW)
    {
        IsWall = true;
        ChangeBallDirection(ball.GetBallDirection());
        IsWall = false;
    }    

    for (int playersBodyIndex = 0; playersBodyIndex < PlayerI::PLAYER_SIZE; playersBodyIndex++)
    {
        if((ball.GetBallCoord().column == player.GetPlayerCoord().column[playersBodyIndex] + 1 && ball.GetBallCoord().row == player.GetPlayerCoord().row[playersBodyIndex])
        || ball.GetBallCoord().column == AIPlayer.GetPlayerCoord().column[playersBodyIndex] - 1 && ball.GetBallCoord().row == AIPlayer.GetPlayerCoord().row[playersBodyIndex])
        {
            TimerMS * Timer = TimerMS::GetInstance();
            Timer->EndTime();
            
            if(Timer->ResultTime() >= TimerMS::EXPIRED_WAIT_TIME_MS)
            {
                ChangeBallDirection(ball.GetBallDirection());
                break;
            }
            else 
            {
                switch (player.GetPlayerAction())
                {
                case eAction::DOWN:
                    ChangeBallDirectionByPlayerMoved(playersBodyIndex, eAction::DOWN);
                    break;
                case eAction::UP:
                    ChangeBallDirectionByPlayerMoved(playersBodyIndex, eAction::UP);
                    break;
                default:
                    break;
                }
            }
            break;
        }
    }
}

void Field::MoveAI()
{
    const int COLUMN_POINT_START_RANDOM = 80;
    const int COLUM_POINT_END_RANDOM = 90;

    srand(time(0));
    int randomAIPlayerMoveChoiceByBallCoord = COLUMN_POINT_START_RANDOM + rand() % (COLUM_POINT_END_RANDOM - COLUMN_POINT_START_RANDOM);

    // logic move AIPlayer. Implement as you want
    if((ball.GetBallDirection() == eDirection::RIGHT || ball.GetBallDirection() == eDirection::DOWNRIGHT 
    || ball.GetBallDirection() == eDirection::UPRIGHT) && ball.GetBallCoord().column >= randomAIPlayerMoveChoiceByBallCoord)
    {
        if(ball.GetBallCoord().row > AIPlayer.GetPlayerCoord().row[PlayerI::PLAYER_CENTER_INDEX])
        {
            AIPlayer.moveDOWN();
        }
        else if(ball.GetBallCoord().row < AIPlayer.GetPlayerCoord().row[PlayerI::PLAYER_CENTER_INDEX])
        {
            AIPlayer.moveUP();
        }
        else
        {
            // stay
        }
    }
}

void Field::MoveBallOnStartPlace()
{
    BallCoord newCoord;
    newCoord.row = GameBall::START_ROW_COORD_BALL;
    newCoord.column = GameBall::START_COLUMN_COORD_BALL;
    ball.SetBallCoord(newCoord);
}

void Field::ChangeBallDirectionByPlayerMoved(int playerBodyIndex, eAction pAction)
{
    // maybe you can add uniq logic for direction ball. i didnt do it because its simple game.
    switch (playerBodyIndex)
    {
    case PlayerI::PLAYER_START_INDEX:
    case PlayerI::PLAYER_SECOND_INDEX:
    case PlayerI::PLAYER_FOURTH_INDEX:
    case PlayerI::PLAYER_LAST_INDEX:
        switch (pAction)
        {
        case eAction::DOWN:
            switch (ball.GetBallDirection())
            {
            case eDirection::NONE:
                break;
            case eDirection::RIGHT:
                ball.SetBallDirection(eDirection::UPLEFT);
                break;
            case eDirection::LEFT:
                ball.SetBallDirection(eDirection::UPRIGHT);
                break;
            case eDirection::UPRIGHT:
                ball.SetBallDirection(eDirection::UPLEFT);
                break;
            case eDirection::UPLEFT:
                ball.SetBallDirection(eDirection::UPRIGHT);
                break;
            case eDirection::DOWNRIGHT:
                ball.SetBallDirection(eDirection::DOWNLEFT);
                break;
            case eDirection::DOWNLEFT:
                ball.SetBallDirection(eDirection::DOWNRIGHT);
                break;
            }
            break;
        case eAction::UP:
            switch (ball.GetBallDirection())
            {
            case eDirection::NONE:
                break;
            case eDirection::RIGHT:
                ball.SetBallDirection(eDirection::DOWNLEFT);
                break;
            case eDirection::LEFT:
                ball.SetBallDirection(eDirection::DOWNRIGHT);
                break;
            case eDirection::UPRIGHT:
                ball.SetBallDirection(eDirection::UPLEFT);
                break;
            case eDirection::UPLEFT:
                ball.SetBallDirection(eDirection::UPRIGHT);
                break;
            case eDirection::DOWNRIGHT:
                ball.SetBallDirection(eDirection::DOWNLEFT);
                break;
            case eDirection::DOWNLEFT:
                ball.SetBallDirection(eDirection::DOWNRIGHT);
                break;
            }
            break;
        }
        break;
    case PlayerI::PLAYER_CENTER_INDEX:
        switch (pAction)
        {
        case eAction::DOWN:
        case eAction::UP:
            ball.SetBallDirection((ball.GetBallDirection() == eDirection::RIGHT || ball.GetBallDirection() == eDirection::DOWNRIGHT 
            || ball.GetBallDirection() == eDirection::UPRIGHT) && ball.GetBallDirection() != eDirection::NONE  ? eDirection::LEFT : eDirection::RIGHT);
            break;
        }
        break;
    default:
        break;
    }
}

void Field::ChangeBallDirection(eDirection oldDirection)
{   
    switch (oldDirection)
    {
    case eDirection::NONE:
        break;
    case eDirection::LEFT:
        ball.SetBallDirection(eDirection::RIGHT);
        break;
    case eDirection::RIGHT:
        ball.SetBallDirection(eDirection::LEFT);
        break;
    case eDirection::UPLEFT:
        if(IsWall)
        {
            ball.SetBallDirection(eDirection::DOWNLEFT);
        }
        else
        {
            ball.SetBallDirection(eDirection::UPRIGHT);
        }
        break;
    case eDirection::UPRIGHT:
        if(IsWall)
        {
            ball.SetBallDirection(eDirection::DOWNRIGHT);
        }
        else
        {
            ball.SetBallDirection(eDirection::UPLEFT);
        }
        break;
    case eDirection::DOWNLEFT:
        if(IsWall)
        {
            ball.SetBallDirection(eDirection::UPLEFT);
        }
        else
        {
            ball.SetBallDirection(eDirection::DOWNRIGHT);
        }
        break;
    case eDirection::DOWNRIGHT:
        if(IsWall)
        {
            ball.SetBallDirection(eDirection::UPRIGHT);
        }
        else
        {
            ball.SetBallDirection(eDirection::DOWNLEFT);
        }
        break;
    default:
        break;
    }
}

