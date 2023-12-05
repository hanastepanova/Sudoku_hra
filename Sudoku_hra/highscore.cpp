
#include "highscore.h"
#include <stdio.h>

// ... your existing functions ...

void update_highscores(score *score, int score) {
    printf("Your time: %d seconds.\n", score);

    char jmeno[50];
    printf("Enter your name: ");
    scanf("%s", jmeno);

    FILE *file = fopen("vystupniSoubor.txt", "a"); // Open file in append mode

    if (file != NULL) {
        fprintf(file, "%s %d\n", jmeno, score);
        fclose(file);
        printf("Highscore saved successfully!\n");
    } else {
        printf("Error saving highscore.\n");
    }
}
