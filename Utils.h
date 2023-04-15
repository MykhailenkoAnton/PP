
#ifndef UTILS_H_
#define UTILS_H_

enum class eAction
{
    NONE,
    DOWN,
    UP
};

enum class eDirection
{
    NONE,
    LEFT,
    RIGHT,
    UPRIGHT,
    UPLEFT,
    DOWNRIGHT,
    DOWNLEFT
};

namespace PlayerI
{
    const int PLAYER_SIZE = 5;
    const int PLAYER_LAST_INDEX = 4;
    const int PLAYER_START_INDEX = 0;
    const int PLAYER_SECOND_INDEX = 1;
    const int PLAYER_CENTER_INDEX = 2;
    const int PLAYER_FOURTH_INDEX = 3;
}

namespace FieldE
{
    const char BOARDER = 'X';
    const char PLAYER = 'P';
    const char BALL = 'O';
    const char EMPTY = ' ';
    const char AIPLAYER = 'A';

    const int ROW = 22;
    const int COLUMN = 100;

    const int START_FIELD_ROW = 0;
    const int START_FIELD_COLUMN = 0;
    const int END_FIELD_ROW = 21;
    const int END_FIELD_COLUMN = 99;
}

namespace GameBall
{
    const int START_ROW_COORD_BALL = 10;
    const int START_COLUMN_COORD_BALL = 49;
}

#endif