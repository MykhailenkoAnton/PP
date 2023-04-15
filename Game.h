#ifndef GAME_H_
#define GAME_H_

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
    bool bExitGame = false;

};

#endif //GAME_H_