#ifndef HIGHSCORE_H
#define HIGHSCORE_H

// Adjust the structure and function declarations based on your requirements

typedef struct {
    char jmeno[50];
    double score;
} scoreEntry;

typedef struct {
    scoreEntry entries[5];  // Assuming you want to store the top 5 highscores
    int count;  // Number of entries in the highscore board
} score;

void display_highscores(const score *score);
void update_highscores(score *score, const char *jmeno, int score);

#endif // HIGHSCORE_H