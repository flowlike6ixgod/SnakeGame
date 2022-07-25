#include "Menu.h"

#include <conio.h>
#include <iostream>

void Menu::MainMenu()
{
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "\t\t\t\t\t\t\t SNAKE GAME\n\n\n";
    std::cout << "\t\t\t\t\t\t\t[START GAME]\n";
    std::cout << "\t\t\t\t\t\t\t  [RECORD]\n";
    std::cout << "\t\t\t\t\t\t\t   [EXIT]\n\n\n\n\n\n\n";

    MenuTips(true);
}

void Menu::MenuTips(bool bIsMenu = true)
{
    if (bIsMenu)
    {
        std::cout << "\t\t\t\t\t\t [PRESS 1 - TO START GAME]\n";
        std::cout << "\t\t\t\t\t       [PRESS 2 - TO OPEN RECORD TAB]\n";
        std::cout << "\t\t\t\t\t\t[PRESS 3 - TO EXIT THE GAME]\n";
    }
    else
    {
        std::cout << "\t\t\t\t\t\t [PRESS 1 - TO START GAME]\n";
        std::cout << "\t\t\t\t\t\t[PRESS 2 - TO EXIT THE GAME]\n";
    }

}

void Menu::EndMenu(int Score)
{
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "\t\t\t\t\t\t\t  YOU DIE! \n\n\n";
    std::cout << "\t\t\t\t\t\t\tYOUR SCORE: " << Score << "\n\n\n";
    MenuTips(false);
}

