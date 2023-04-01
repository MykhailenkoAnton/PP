#include "GameElement/Field.h"

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