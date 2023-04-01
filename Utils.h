#ifndef UTILS_H_
#define UTILS_H_

enum class eAction
{
    NONE,
    DOWN,
    UP,
    RIGHT,
    LEFT
};

namespace PlayerI
{
    const int PLAYER_SIZE = 5;
    const int PLAYER_LAST_INDEX = 4;
    const int PLAYER_START_INDEX = 0;
}

namespace FieldE
{
    const char BOARDER = 'X';
    const char PLAYER = 'P';
    const char BALL = 'O';
    const char EMPTY = ' ';

    const int ROW = 22;
    const int COLUMN = 100; 
}

#endif