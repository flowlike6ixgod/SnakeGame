#pragma once
#include "UI.h"

class ScoreBoard
{
public:
    ScoreBoard();
private:
    /* Points earned during the game */
    int CurrentScore;

    /* Max maximum points achieved */
    int RecordScore;

public:
    /* Get current score */
    int GetCurrentScore() const { return CurrentScore; }

    /** Called when the score value changes
     * @param NewScore - new points for eating fruit
     */
    void OnPointsChanged(int NewScore);

    /* Reset score to zero */
    void ResetScore();

    /* Read record to file */
    int ReadRecord();

private:
    /* Write new record to file */
    void WriteRecord();



};
