#pragma once
#include "ScoreBoard.h"

class Menu;
class ScoreBoard;

class UI
{
public:
    UI();
    ~UI();
private:
    Menu* menu;

    ScoreBoard* ScoreBrd;

public:

    /* Returns pointer to ScoreBoard class */
    ScoreBoard *GetScoreBoard() { return *&ScoreBrd; }

    /** Shows score in game
     * @param bIsMenu - checks if we are in the menu
     */
    void ShowScore(bool bIsMenu);

    /** Shows main menu */
    void ShowMainMenu();

    /** Shows end menu */
    void ShowEndMenu();

    /** Close game */
    void Close();

private:
    void SetConsoleSettings();
};
