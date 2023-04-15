#ifndef MENU_H_
#define MENU_H_

#include <Windows.h>
#include <conio.h>

#include <string>
#include <vector>

enum eMenuItem
{
    FIRST,
    SECOND,
    THIRD
};

enum eColorIndex
{
    DEFAULT_COLOR_INDEX = 7,
    RED_COLOR_INDEX = 12
};

struct MenuItem
{
    std::string Line;
    int color;
    bool IsActive;
};

class GameMenu
{
public:
    GameMenu();
    ~GameMenu();
    void ShowMenu();

private:
    void gotoxy(int x, int y);
    void color(int color);

    void SetColorAsDefault();
    void ShowMenuItemOnScreen();
    void SetActiveColorByCounter(int counter);

    void SetCursorVisible(bool visible);
    void SetActiveMenuItem(int counter);

private:
    std::vector<MenuItem> menuItem;
    char key;
};

#endif //MENU_H_