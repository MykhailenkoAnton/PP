#include "Game.h"
#include "GameElement/Menu.h"

#include <thread>
#include <iostream>
#include <conio.h>

void PingPongGame::run()
{
    GameMenu * menu = new GameMenu();
    menu->ShowMenu();

    std::thread input = std::thread(&PingPongGame::UserChoice, this);
    input.detach();

    delete menu;
    std::cout << "RIGHT LOGIC!\n";
    while(false)
    {
        
    }
}

void PingPongGame::UserChoice()
{
    while(true)
    {
        const auto Input = getUserChoice();
        std::cout << "IPUT!!!!";
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
        exit(0);
        break;
    default:
        break;
    }
    return eAction::NONE;
}