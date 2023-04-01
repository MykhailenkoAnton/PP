#pragma once

struct BallCoord
{
    int row;
    int column;
};

class PPBall
{
private:

    BallCoord ballCoord;

public:
    PPBall();

    BallCoord GetBallCoord() const {return ballCoord;}
};
