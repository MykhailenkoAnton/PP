#include "Menu.h"
#include "iostream"

GameMenu::GameMenu()
{
    menuItem.push_back({"START GAME", 12, false});
    menuItem.push_back({"AUTHOR", 7, false});
    menuItem.push_back({"EXIT", 7, false});
}

GameMenu::~GameMenu()
{
    system("cls");
}

void GameMenu::ShowMenu()
{
    int counter = 0;
    const int ENTER_KEY = 13;

    SetCursorVisible(false);

    while (true)
    {
        ShowMenuItemOnScreen();

        key = _getch();
        if(key == 'w' && counter > 0)
        {
            counter--;
            
        }
        if (key == 's' && (counter >= 0 && counter < 2))
        {
            counter++;
        }

        SetColorAsDefault();
        SetActiveColorByCounter(counter);

        if(key == ENTER_KEY)
        {
            if(menuItem[FIRST].IsActive == true)
            {
                break;
            }
            else if(menuItem[SECOND].IsActive == true)
            {
                COORD StartPointDispayAuthorName;
                StartPointDispayAuthorName.X = 4;
                StartPointDispayAuthorName.Y = 10;

                gotoxy(StartPointDispayAuthorName.X, StartPointDispayAuthorName.Y);
                std::cout << authorName;
            }
            else
            {
                exit(0);
            }
        }

    }
    
}

void GameMenu::gotoxy(int x, int y)
{
    COORD newColor;
    newColor.X = x;
    newColor.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), newColor);
}

void GameMenu::color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void GameMenu::SetColorAsDefault()
{
    for(int i = 0; i < menuItem.size(); i++)
    {
        menuItem[i].color = DEFAULT_COLOR_INDEX;
    }
}

void GameMenu::ShowMenuItemOnScreen()
{
    COORD goroxyStartCoord;
    goroxyStartCoord.X = 8;
    goroxyStartCoord.Y = 5;

    for(int i = 0; i < menuItem.size(); i++)
    {
        gotoxy(goroxyStartCoord.X, goroxyStartCoord.Y + i);
        color(menuItem[i].color);
        std::cout << menuItem[i].Line;
    }
}

void GameMenu::SetActiveColorByCounter(int counter)
{
    switch (counter)
    {
    case FIRST:
        menuItem[counter].color = RED_COLOR_INDEX;
        SetActiveMenuItem(counter);
        break;
    case SECOND:
        menuItem[counter].color = RED_COLOR_INDEX;
        SetActiveMenuItem(counter);
        break;
    case THIRD:
        menuItem[counter].color = RED_COLOR_INDEX;
        SetActiveMenuItem(counter);
        break;
    
    default:
        break;
    }
}

void GameMenu::SetCursorVisible(bool visible)
{
    HANDLE hStdOut = NULL;
    CONSOLE_CURSOR_INFO curInfo;

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &curInfo);
    
    curInfo.bVisible = visible;
    SetConsoleCursorInfo(hStdOut, &curInfo);
}

void GameMenu::SetActiveMenuItem(int counter)
{
    for(int i = 0; i < menuItem.size(); i++)
    {
        menuItem[i].IsActive = false;

        if(i == counter)
        {
            menuItem[i].IsActive = true;
        }
    }
}


