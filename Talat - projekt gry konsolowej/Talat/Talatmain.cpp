#include <cstdio>
#include <windows.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include "Gra.h"
#include "Plansza.h"
#include "Vs2Players.h"
#include "VsPlayer.h"
#include <fstream>

using namespace std;




/////////////////// SZABLON /////////////////////////
template <class TypPrzyjety, class TypZwracany>
TypZwracany podliczanie(TypPrzyjety P1 , TypPrzyjety P2, TypPrzyjety P3)
{
	TypZwracany wynik;
	wynik = (TypZwracany)P1 + (TypZwracany)P2 + (TypZwracany)P3;

	return wynik;
}
/////////////////// SZABLON /////////////////////////




int main() 
{
	HANDLE hOut; // do kolorow
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); // standardowy kolor

	int wybor = 0, koniec = 0;
	fstream logi, wyniki;
	char wynik[225];
	Gra *glowa = NULL, *wsk = NULL;
	logi.open("logi.txt", std::ios::out | std::ios::app | std::ios::in);


	SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	cout << endl;
	cout << "                            '########::::'###::::'##::::::::::'###::::'########:" << endl;
	cout << "                            ... ##..::::'## ##::: ##:::::::::'## ##:::... ##..::" << endl;
	cout << "                            ::: ##:::::'##:. ##:: ##::::::::'##:. ##::::: ##::::" << endl;
	cout << "                            ::: ##::::'##:::. ##: ##:::::::'##:::. ##:::: ##::::" << endl;
	cout << "                            ::: ##:::: #########: ##::::::: #########:::: ##::::" << endl;
	cout << "                            ::: ##:::: ##.... ##: ##::::::: ##.... ##:::: ##::::" << endl;
	cout << "                            ::: ##:::: ##:::: ##: ########: ##:::: ##:::: ##::::" << endl;
	cout << "                            :::..:::::..:::::..::........::..:::::..:::::..:::::" << endl;
	cout << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	



	if (logi.good() == true) // tu logi
		cout << "--> Logi sa od teraz zapisywane!" << endl << endl;
	else 
		cout << "--> Logi nie sa zapisywane!" << endl << endl;


	logi << "Uruchomiono program" << endl;

	cout << "##################################################################################################################" << endl;
	cout << "#                                        Witaj w grze Talat!                                                     #" << endl;
	cout << "#                                                                                                                #" << endl;
	cout << "# Gra posiada 2 tryby, dla 3 oraz dla 2 graczy + PC                                                              #" << endl;
	cout << "# Wyniki zakonczonych gier zapisywane sa do pliku.                                                               #" << endl;
	cout << "#                                                                                                                #" << endl;
	cout << "#   * Kazdy gracz ma po 9 pionkow                                                                                #" << endl;
	cout << "#   * Ustawianie pionkow odbywa sie na zmiane, kazdy ma 9 pionkow, kazdy moze ustawiac tylko na dwoch planszach. #" << endl;
	cout << "#   * Gracz 1. moze ustawiac na planszach 1(pola 1-5) i 2(pola 1-5),                                             #" << endl;
	cout << "#   * Gracz 2. na planszach 2(pola 21-25) i 3(pola 21-25),                                                       #" << endl;
	cout << "#   * Gracz 3. na planszach 1(pola 21-25) ) i 3(pola 1-5)                                                        #" << endl;
	cout << "#                                                                                                                #" << endl;
	cout << "##################################################################################################################" << endl << endl;

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
	cout << "PLANSZA JEST USTAWIONA POZIOMO" << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	wyniki.open("wyniki.txt", std::ios::in);
	cout << "Ostatnie wyniki w kolejnosci od najstarszych:" << endl;
	/*while (wyniki.eof() == false) {
		
		wyniki.getline(wynik, 225);
		cout << wynik << endl;
	}
	wyniki.close();
	*/
	while (1)
	{
		logi << "Rozpoczeto rozgrywke" << endl;
		int wybor;
		cout << endl;
		cout << "Podaj tryb gry w jakim chcesz grac!" << endl << "--> (1) - 3 graczy" << endl << "--> (2) - 2 graczy + PC" << endl << endl << "--> ";

		while (!(cin >> wybor) || wybor < 1 || wybor > 2 || getchar() != '\n') 
		{
			cout << endl;
			cout << "#########################################" << endl;
			cout << "Nie ma takiego trybu! Wprowadz ponownie #" << endl;
			cout << "#########################################" << endl;
			cout << "--> ";
			cin.clear();
			cin.ignore('\n');
		}
		if(wybor == 1)// lista dynamiczna potrzebna do polimorfizmu 
		{
			if (glowa == NULL) 
			{
				glowa = new Vs2Players();
				wsk = glowa;
				wsk->nast = NULL;
			}

			else 
			{
				wsk->nast = new Vs2Players();
				wsk = wsk->nast;
				wsk->nast = NULL;
			}
		}

		else if (wybor == 2)
		{
			if (glowa == NULL)
			{
				glowa = new VsPlayer();
				wsk = glowa;
				wsk->nast = NULL;
			}


			else
			{
				wsk->nast = new VsPlayer();
				wsk = wsk->nast;
				wsk->nast = NULL;
			}
		}


		logi << "Wybrano tryb rozgrywki nr:" << wybor << endl;
		logi << "Rozpoczeto faze ustawiania pionkow" << endl;
		glowa->ustawianiePionkow();// metoda w vs2players lub vsplayer
		logi << "Zakonczono rozstawianie pionkow" << endl;
		logi << "Rozpoczeto wlasciwa rozgrywke" << endl;
		glowa->rozgrywka(); // metoda jak wyzej
		logi << "Zakonczono wlasciwa rozgrywke" << endl;
		glowa->wyswietlaniePunktow(); // metoda w klasie Gra
		
		logi << "Punkty gracza nr1:" << glowa->getpunkty1() << "Punkty gracza nr2:" << glowa->getpunkty2() << "Punkty gracza nr3:" << glowa->getpunkty3() << endl;
		wyniki.open("wyniki.txt", ios::out | ios::app);
		wyniki << "Punkty gracza nr1:" << glowa->getpunkty1() << "Punkty gracza nr2:" << glowa->getpunkty2() << "Punkty gracza nr3:" << glowa->getpunkty3() << endl;
		wyniki.close();
		cout << "Suma zdobytych punktow w grze" << podliczanie<int,float>(glowa->getpunkty1(), glowa->getpunkty2(), glowa->getpunkty3()) << endl;
		cout << "Jak chcesz zagrac jeszcze raz wpisz 1, jesli nie inna liczbe" << endl;
		while (!(cin >> koniec) || getchar() != '\n')
		{
			cout << endl;
			cout << "############################################" << endl;
			cout << "# Podaj prawidlowe dane! Wprowadz ponownie #" << endl;
			cout << "############################################" << endl;
			cout << "--> ";
			cin.clear();
			cin.ignore();
		}
		if (koniec != 1) {
			break;
		}
	}
	logi.close();
}