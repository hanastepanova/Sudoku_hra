#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>

struct ScoreEntry {
    std::string playerName;
    int score;
};

class Highscore {
public:
    Highscore();
    void addHighscore(const std::string &playerName, int score);
    void printHighscores() const;

private:
    std::vector<ScoreEntry> highscores;
    void loadHighscores();
    void saveHighscores() const;
};

#endif // HIGHSCORE_H
