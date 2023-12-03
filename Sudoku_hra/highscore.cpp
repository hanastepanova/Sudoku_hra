#include "highscore.h"
#include <iostream>
#include <fstream>

Highscore::Highscore() {
    // Load highscores from file during object creation
    loadHighscores();
}

void Highscore::addHighscore(const std::string &playerName, int score) {
    highscores.push_back({playerName, score});

    // Sort highscores in ascending order based on score
    std::sort(highscores.begin(), highscores.end(), [](const ScoreEntry &a, const ScoreEntry &b) {
        return a.score < b.score;
    });

    // Keep only the top 5 highscores
    if (highscores.size() > 5) {
        highscores.pop_back();
    }

    // Save updated highscores to file
    saveHighscores();
}

void Highscore::printHighscores() const {
    std::cout << "Highscores:\n";
    for (const auto &entry : highscores) {
        std::cout << entry.playerName << ": " << entry.score << " moves\n";
    }
}

void Highscore::loadHighscores() {
    std::ifstream file("vystupniSoubr.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening highscores file.\n";
        return;
    }

    highscores.clear();  // Clear existing highscores

    std::string playerName;
    int score;

    while (file >> playerName >> score) {
        highscores.push_back({playerName, score});
    }

    file.close();
}

void Highscore::saveHighscores() const {
    std::ofstream file("vystupniSoubor.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening highscores file for writing.\n";
        return;
    }

    for (const auto &entry : highscores) {
        file << entry.playerName << " " << entry.score << "\n";
    }

    file.close();
}
