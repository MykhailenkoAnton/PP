#ifndef PPBALL_H_
#define PPBALL_H_

#include "../../Utils.h"


struct BallCoord
{
    int row;
    int column;
};

class PPBall
{
public:
    PPBall();
    
    void Move();

    void SetBallDirection(eDirection newDidection);
    void SetBallCoord(BallCoord newCoord);
    eDirection GetBallDirection();
    BallCoord GetBallCoord() const;

private:

    BallCoord ballCoord;
    eDirection direction;

    void MoveBallRIGHT();
    void MoveBallLEFT();
    void MoveBallUPRIGHT();
    void MoveBallUPLEFT();
    void MoveBallDOWNRIGHT();
    void MoveBallDOWNLEFT();
};

#endif //PPBALL_H_