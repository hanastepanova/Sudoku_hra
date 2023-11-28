// Sudoku_hra.cpp: Definuje vstupní bod pro aplikaci.
//

#include "Sudoku_hra.h"
#include <cstdlib>
#include <cstring>

using namespace std;

const int N = 9;




void uvodniTabule(int tabulka[N][N])
{

	for (int radek = 0; radek < N; radek++)
	{
		for (int sloupec = 0; sloupec < N; sloupec++)
		{
			if (sloupec == 3 || sloupec == 6)
				printf("|");
			printf(" "); 

			}

		if (radek == 2 || radek == 5)
		{
			for (int i = 0; i < N; i++)
				printf("---");

			}
	}
}

bool kontrola(int pole[N][N], int radek, int sloupec, int cislo)
{
	for (int i = 0; i < N; i++)
		if (pole[radek][i] == cislo)
			return false;
	for (int i = 0; i < N; i++)
		if (pole[i][sloupec] == cislo)
			return false;

	int zacatekRadku = radek - radek % 3;
	int zacatekSloupce = sloupec - sloupec % 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (pole[i + zacatekRadku][j + zacatekSloupce] == cislo)
				return false;
	return true;

}
int main()
{
	int pole[N][N] =
	{
		//otevre soubor sudoku1 - TODO
	};

	printf("=============================================================================================\n");
	printf("<3                                                                                         <3\n");
	printf("<3                                           SUDOKU                                        <3\n");
	printf("<3                                                                                         <3\n");
	printf("=============================================================================================\n");
	printf("Vitame Vas u hry Sudoku!\n Stisknete 1, pokud chcete zacit hrat!\n Stisknete 2, pokud chcete zobrazit reseni.\n Stisknete 3, pokud chcete zobrazit tabulku nejvyssich score.\n \n \n");
	printf("Mnoho zdaru pri hre!\n \n");




	return 0;
}
