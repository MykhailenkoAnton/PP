#ifndef FIELD_H_
#define FIELD_H_

#include "Player/AI/PlayerAI.h"
#include "PPBall.h"

class Field
{
public:
    Field();
    ~Field();
    void ShowField();
    void ShowPlayerOnField();
    void ShowAIPlayerOnField();
    void ShowBallOnField();
    void PlayerMove(eAction ActionMove);
    void ClearFieldElement(char body);

    void MoveBall();

    void SetPlayerMove(bool pMove);
    void ChangeBallDirection(eDirection oldDirection);

    void MoveAI();


private:
    void MoveBallOnStartPlace();
    void ChangeBallDirectionByPlayerMoved(int playerBodyIndex, eAction pAction);

    char field[FieldE::ROW][FieldE::COLUMN];
    void FillField();

    Player player;
    PlayerAI AIPlayer;
    PPBall ball;

    bool IsWall = false;

};

#endif //FIELD_H_