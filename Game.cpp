#include "Game.h"
#include "GameElement/Menu.h"
#include "Utils.h"

#include <windows.h>
#include <iostream>
#include <thread>
#include <iostream>
#include <conio.h>


void PingPongGame::run()
{
    GameMenu * menu = new GameMenu();
    menu->ShowMenu();
    delete menu;

    std::thread input = std::thread(&PingPongGame::UserChoice, this);
    input.detach();

    std::thread fieldDraw = std::thread(&PingPongGame::DrawField, this);
    fieldDraw.detach();

    while(!bExitGame)
    {
        field.MoveBall();
        field.MoveAI();
        Sleep(25);
    }
}

void PingPongGame::UserChoice()
{
    while(true)
    {
        const auto Input = getUserChoice();
        switch (Input)
        {
        case eAction::UP:
            field.PlayerMove(eAction::UP);
            break;
        case eAction::DOWN:
            field.PlayerMove(eAction::DOWN);
            break;
        case eAction::NONE:
            break;
        default:
            break;
        }
    }
}

eAction PingPongGame::getUserChoice()
{
    char ch = _getch();
    switch (ch)
    {
    case 's':
        return eAction::DOWN;
        break;
    case 'w':
        return eAction::UP;
        break;
    case 'q':
        bExitGame = true;
        break;
    default:
        return eAction::NONE;
        break;
    }
    
    return eAction::NONE;
}

void PingPongGame::DrawField()
{
    while (true)
    {
        field.ShowField();
        field.ShowPlayerOnField();
        field.ShowAIPlayerOnField();
        field.ShowBallOnField();
    }
}
