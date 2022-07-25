#include "ScoreBoard.h"
#include <fstream>
#include <iostream>

ScoreBoard::ScoreBoard()
{
    CurrentScore = 0;
    RecordScore = 0;
}

void ScoreBoard::OnPointsChanged(int NewScore)
{
    // Add new points to exist
    CurrentScore += NewScore;
    // if curr score greater than record, write to file
    if (CurrentScore > RecordScore)
    {
        RecordScore = CurrentScore;
        WriteRecord();
    }
}

void ScoreBoard::ResetScore()
{
    CurrentScore = 0;
}

void ScoreBoard::WriteRecord()
{
    std::ofstream out;
    // file creates in folder with .exe
    out.open("Record.txt");
    if (out.is_open())
    {
        // write score to file
        out << RecordScore << std::endl;
    }
    out.close();
}

int ScoreBoard::ReadRecord()
{
    int Record;

    std::ifstream in("Record.txt");
    if (in.is_open())
    {
        while (in >> Record)
        {
            // Read score from file and assign to RecordScore
            RecordScore = Record;
        }
    }
    in.close();

    return RecordScore;
}
