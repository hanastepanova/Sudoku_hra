// Sudoku_hra.cpp: Definuje vstupní bod pro aplikaci.
//

#include "Sudoku_hra.h"
#include <cstdlib>
#include <cstring>
#include <chrono>
#include <iostream>
#include <windows.h>
#include "highscore.h"

using namespace std;

const int N = 9;

bool kontrola(int pole[N][N], int radek, int sloupec, int cislo)
{ //kontrola, jestli cislo uz neni ve stejnem radku
	for (int i = 0; i < N; i++)
		if (pole[radek][i] == cislo)
			return false;
	//kontrola, jestli neni ve stejnem sloupci
	for (int i = 0; i < N; i++)
		if (pole[i][sloupec] == cislo)
			return false;
	//kontrola, jestli cislo uz neni v tom malem ctverecku
	int zacatekRadku = radek - radek % 3;
	int zacatekSloupce = sloupec - sloupec % 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (pole[i + zacatekRadku][j + zacatekSloupce] == cislo)
				return false;

	return true;

}

void uvodniTabule(int tabulka[N][N])
{
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("<3                                                                                         <3\n");
	printf("<3                                           SUDOKU                                        <3\n");
	printf("<3                                                                                         <3\n");
	printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
	printf("PRAVIDLA: Umistete cisla 1-9 misto 0 tak, aby se v radku, sloupci ani \n v malem ctverecku zadne cislo neopakovalo. Behem hry se Vam zapocitava \n cas, pricemz nejrychlejsi hraci jsou zapsani do tabulky nejvyssich score.\n");
	printf("\nMnoho zdaru pri hre!\n");
	for (int radek = 0; radek < N; radek++)
	{
		for (int sloupec = 0; sloupec < N; sloupec++)
		{
			if (sloupec == 3 || sloupec == 6)
				printf("|");
			printf(" %d", tabulka[radek][sloupec]);
		}

		if (radek == 2 || radek == 5)
		{
			printf("\n");
			for (int i = 0; i < N; i++)
				printf(" -");
		}
		printf("\n");
	}
}

bool reseniSudoku(int pole[N][N], int radek, int sloupec)
{
	if (radek == N - 1 && sloupec == N)
		return true;

	if (sloupec == N)
	{
		radek++;
		sloupec = 0;
	}

	if (pole[radek][sloupec] != 0)
		return reseniSudoku(pole, radek, sloupec + 1);

	for (int cislo = 1; cislo <= 9; cislo++)
	{
		if (kontrola(pole, radek, sloupec, cislo))
		{
			pole[radek][sloupec] = cislo;

			if (reseniSudoku(pole, radek, sloupec + 1))
				return true;
			pole[radek][sloupec] = 0;
		}

	}
	return false;
}

bool kompletniReseni(int tabulka[N][N])
{
	for (int radek = 0; radek < N; radek++)
		for (int sloupec = 0; sloupec < N; sloupec++)
			if (tabulka[radek][sloupec] == 0)
				return false;

	return true;

}

void hratSudoku(int pole[N][N])
{
	int volba;
	int radek, sloupec, cislo;

	while (true)
	{
		uvodniTabule(pole);
		printf("\n");
		printf("\nNemuzete vyresit sudoku? Zadejte 0 misto radku, sloupce i cisla pro zobrazeni reseni.\nBudete chtit pokracovat ve hre priste? Napiste 'P' misto radku, sloupce i cisla pro ulozeni Vasi hry.\n");
		printf("Cislo radku: ");
		scanf(" %d", &radek);
		printf("Cislo sloupce: ");
		scanf(" %d", &sloupec);
		printf("Cislo, ktere chcete zadat: ");
		scanf(" %d", &cislo);

		if (radek == 0 || sloupec == 0 || cislo == 0)
		{
			reseniSudoku(pole, 0, 0);
			printf("Vyresene sudoku:");
			printf("\n");
			uvodniTabule(pole);
			printf("\n");

			//bool vyplneno = kompletniReseni(pole);

			if (kompletniReseni(pole))
			{
				printf("\nGratuluji k vyreseni sudoku!");
			}
			else
			{
				printf("\nSudoku nebylo vyreseno spravne. Zkuste to znovu.");
			}
			return;
		}

		if (kompletniReseni(pole))
		{
			break;
		}

		radek--;
		sloupec--;


		if (!kontrola(pole, radek, sloupec, cislo))
		{
			printf("\nNeni mozne doplnit toto cislo. Zkuste to znovu.\n");
			continue;
		}
		pole[radek][sloupec] = cislo;

	}

	if (kompletniReseni(pole))
	{
		printf("\nGratuluji k vyreseni sudoku!");
		uvodniTabule(pole);
	}
	else
	{
		printf("\nSudoku nebylo vyreseno spravne. Zkuste to znovu!");

	}


	//bool vyreseno = true; 

	//for (int i = 0; i < N; ++i) 
	//{
		//for (int j = 0; j < N; ++j)
		//{
			//if (pole[i][j] == 0)
			//{
			//	vyreseno = false; 
			//	break;
			//}
	//	}
//	if (!vyreseno)
	//	{
	//		break;
	//	}
	//}



	//if (vyreseno)  
	//{
	//	printf("\nGratuluji k vyreseni sudoku!"); 
	//	uvodniTabule(pole);
	//}

//	else {
	//	printf("\nSudoku nebylo vyreseno. Zkuste to znovu!");
	//}
}


int main()
{

	int pole[N][N];

	const char* vstupniCesta = "C:\\Users\\42060\\source\\repos\\Sudoku_hra\\sudoku02.txt";


	FILE* vstupniSoubor;

	if (fopen_s(&vstupniSoubor, vstupniCesta, "r"))
	{
		printf("Soubor se nepodarilo otevrit.\n");
		return -1;

	}

	for (int radek = 0; radek < N; radek++)
	{
		for (int sloupec = 0; sloupec < N; sloupec++)
		{
			if (fscanf_s(vstupniSoubor, "%d", &pole[radek][sloupec]) != 1)
			{
				printf("Nacitani sudoku z textoveho souboru selhalo.\n");
				fclose(vstupniSoubor);
				return -1;
			}

		}

	}



	//v pripade, ze bychom chteli doplnit tabulku sudoku odsud
	//int pole [N][N] =
	// {
		//{3, 0, 6, 5, 0, 8, 4, 0, 0},
		//{5, 2, 0, 0, 0, 0, 0, 0, 0},
		//{0, 8, 7, 0, 0, 0, 0, 3, 1},
		//{0, 0, 3, 0, 1, 0, 0, 8, 0},
		//{9, 0, 0, 8, 6, 3, 0, 0, 5},
		//{0, 5, 0, 0, 9, 0, 6, 0, 0},
		//{1, 3, 0, 0, 0, 0, 2, 5, 0},
		//{0, 0, 0, 0, 0, 0, 0, 7, 4},
		//{0, 0, 5, 2, 0, 6, 3, 0, 0}
		//};

	printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("<3                                                                                         <3\n");
	printf("<3                                           SUDOKU                                        <3\n");
	printf("<3                                                                                         <3\n");
	printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");


	while (true)
	{
		int volba;
		printf("\nVitame Vas u hry Sudoku! Jste pripraveni zucastnit se teto vzrusujici hry?\n\n Stisknete 1, pokud chcete zacit hrat!\n Stisknete 2, pokud chcete zobrazit reseni.\n Stisknete 3, pokud chcete zobrazit tabulku nejvyssich score.\n");
		printf("Vase volba: \n");
		scanf("%d", &volba);

		switch (volba)
		{
		case 1:
			hratSudoku(pole);

			break;
		case 2:
			if (reseniSudoku(pole, 0, 0))
			{
				printf("\nVyresene sudoku: \n");
				printf("\n \n");
				for (int radek = 0; radek < N; radek++)
				{
					for (int sloupec = 0; sloupec < N; sloupec++)
					{
						if (sloupec == 3 || sloupec == 6)
							printf(" | ");
						printf(" %d", pole[radek][sloupec]);

					}
					if (radek == 2 || radek == 5)
					{
						printf("\n");
						for (int i = 0; i < N; i++)
							printf(" - -");
					}
					printf("\n");

				}
				printf("\n");
				printf("\nZkuste to priste!");

			}
			else
				printf("\nReseni nebylo nalezeno.\n");
			break;
		case 3:
			exit(0);
		default:
			printf("\nNespravna volba.\n");

		}
		return 0;
	}



	return 0;
}
