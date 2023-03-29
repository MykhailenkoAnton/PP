#include "GameElement/Field.h"

enum class eAction
{
    NONE,
    DOWN,
    UP,
    RIGHT,
    LEFT
};

class PingPongGame
{

public:
    void run();
    void UserChoice();

    eAction getUserChoice();
    void DrawField();

private:
    Field field;
};