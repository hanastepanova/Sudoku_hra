#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#pragma once;
#include <stdio.h>

typedef struct {
	char jmeno[50];
	double score;
} scoreEntry;

typedef struct {
	scoreEntry entries[5];
	int count;
} score;

//void displayHighscore(const score* score);
void updateHighscore(double score) {



	char jmeno[50];
	printf("Zadejte Vase jmeno: ");
	scanf("%s", jmeno);

	printf("Highscoreboard si muzete prohlednout v souboru: vystuniSoubor\n"); 


	const char* vystuniCesta = "C:\\Users\\42060\\source\\repos\\Sudoku_hra\\vystuniSoubor.txt";


	FILE* file;

	if (fopen_s(&file, vystuniCesta, "a")) {
		printf("Chyba v ulozeni score.\n");
	}

	fprintf(file, "%s, %lf\n", jmeno, score);
	fclose(file);
	printf("Score ulozeno bez problemu.\n");
	
	
}

#endif
