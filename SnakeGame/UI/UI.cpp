#include "UI.h"
#include <iostream>
#include "ScoreBoard.h"
#include <Windows.h>

#include "Menu.h"

UI::UI()
{
    ScoreBrd = new ScoreBoard;
    menu = new Menu;
    SetConsoleSettings();
}

void UI::ShowScore(bool bIsMenu)
{
    if (bIsMenu)
    {
        std::cout << "\n\n";
        std::cout << "\t\t\t\t\t\t     RECORD SCORE : " << ScoreBrd->ReadRecord();
    }
    else
    {
        std::cout << "\n\t\t\t\t\t Score: " << ScoreBrd->GetCurrentScore() << "\t\t\t   Record Score: " << ScoreBrd->ReadRecord();
    }
}

void UI::ShowMainMenu()
{
    menu->MainMenu();
}

void UI::ShowEndMenu()
{
    menu->EndMenu(ScoreBrd->GetCurrentScore());
}

void UI::Close()
{
    exit(0);
}

void UI::SetConsoleSettings()
{
    // Sets console size
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1005, 602, TRUE);

    // Sets console color
    HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(ConsoleHandle, 0x01 | BACKGROUND_INTENSITY);
}

UI::~UI()
{
    delete ScoreBrd;
    delete menu;
}
