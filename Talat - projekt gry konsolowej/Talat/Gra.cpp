#include "Gra.h"
#include "Plansza.h"
#include <iostream>

using namespace std;


Gra::Gra():liczbaPunktowGracz1(0), liczbaPunktowGracz2(0), liczbaPunktowGracz3(0)
{
	for (int i = 0; i < 3; i++) // deklaracja 3x plansz
		plansze[i] = new Plansza();
}


Gra::~Gra()
{
	for (int i = 0; i < 3; i++)
		delete plansze[i];
}

int Gra::getpunkty1()
{
	return liczbaPunktowGracz1;
}

int Gra::getpunkty2()
{
	return liczbaPunktowGracz2;
}

int Gra::getpunkty3() 
{ 
	return liczbaPunktowGracz3;
}

void Gra::wypiszPlansze() 
{
	system("cls");  // czyszczenie konsoli
	for (int i = 0; i < 3; i++) 
	{
		cout << "----------------------------------------------------" << endl;
		if (plansze[i]->czyDaSieBic(i) == false)
			cout << "\tZAMROZONA:\t" << endl;
		plansze[i]->wyswietlPlansze();
		cout << "----------------------------------------------------" << endl;
	}
}

void Gra::interfejs(int gracz) //to jest interfejs ktory sie powtarza dla kazdego z graczy
{ 
	int numer, co, gdzie, naKtorejPlanszy;
	while (1) 
	{
		cout << "Na ktorej planszy chcesz wykonac akcje?" << endl;
		cout << "-->";

		cin >> naKtorejPlanszy;

		if (naKtorejPlanszy < 1 || naKtorejPlanszy>3) {
			cout << endl;
			cout << "##########################################" << endl;
			cout << "# Podales zla plansze! Wprowadz ponownie #" << endl;
			cout << "##########################################" << endl;
			cout << "-->";
			continue;
		}
		naKtorejPlanszy --;


		if (plansze[naKtorejPlanszy]->czyDaSieBic(naKtorejPlanszy) == false) // metoda sprawdza czy da sie bic na planszy wybranej
		{ 
			cout << "###############################" << endl;
			cout << "# Nie mozna bic! Ponow probe! #" << endl;
			cout << "###############################" << endl;
			continue;
		}


		cout << "Podaj nr pola na ktorym stoi pionek, ktorym chcesz wykonac akcje" << endl;
		cout << "-->";
		while (!(cin >> numer) || getchar() != '\n')
		{
			cout << endl;
			cout << "######################################" << endl;
			cout << "# Podano zle pole! Wprowadz ponownie #" << endl;
			cout << "######################################" << endl;
			cout << "-->";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		if (plansze[naKtorejPlanszy]->sprawdzCzyDotarl(numer, gracz, naKtorejPlanszy)) //sprawdza czy pionek dotarl do mety, jezeli dotarl to nie mozna z nim nic robic i dodaje punkty na koncu
		{ 
			cout << endl;
			cout << "###############################################" << endl;
			cout << "# Tym pionkiem nie mozna ruszac! Ponow probe! #" << endl;
			cout << "###############################################" << endl;
			continue;
		}
		cout << endl;
		cout << "Co chcesz zrobic?" << endl;
		cout << "--> 1 - idz," << endl;
		cout <<	"--> 2 - atakuj" << endl << endl;
		cout << "-->";

		while (!(cin >> co) || getchar() != '\n')
		{
			cout << endl;
			cout << "##########################################" << endl;
			cout << "# Nie ma takiej opcji! Wprowadz ponownie #" << endl;
			cout << "##########################################" << endl;
			cout << "-->";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		if (co == 1) 
		{
			cout << "Gdzie chcesz isc?" << endl;
			cout << "--> 1 - w prodz" << endl;
			cout << "--> 2 - lewy skos" << endl;
			cout << "--> 3 - prawy skos" << endl;

			while (!(cin >> gdzie) || getchar() != '\n')
			{
				cout << endl;
				cout << "##########################################" << endl;
				cout << "# Nie ma takiej opcji! Wprowadz ponownie #" << endl;
				cout << "##########################################" << endl;
				cout << "-->";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			if(plansze[naKtorejPlanszy]->idz(numer, gdzie, gracz, naKtorejPlanszy)) //funckja idz w Plansza
				break;
		}

		else if (co == 2) 
		{
			cout << "Gdzie chcesz atakowac?" << endl;
			cout << "--> 1 - w prodz" << endl;
			cout << "--> 2 - lewy skos" << endl;
			cout << "--> 3 - prawy skos" << endl;
			cout << "--> 4 - lewo" << endl;
			cout << "--> 5 - prawo" << endl;

			while (!(cin >> gdzie) || getchar() != '\n')
			{
				cout << endl;
				cout << "##########################################" << endl;
				cout << "# Nie ma takiej opcji! Wprowadz ponownie #" << endl;
				cout << "##########################################" << endl;
				cout << "-->";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			if (plansze[naKtorejPlanszy]->atakuj(numer, gdzie, gracz, naKtorejPlanszy)) { //metoda w Plansza
				switch (gracz) {
				case 1:
					liczbaPunktowGracz1 += 5;
					break;
				case 2:
					liczbaPunktowGracz2 += 5;
					break;
				case 3:
					liczbaPunktowGracz3 += 5;
					break;
				}
				break;
			}
		}
		cout << "######################" << endl;
		cout << "# Blad! Ponow probe! #" << endl; //je¿eli gdziekolwiek cos sie nie zgadza
		cout << "######################" << endl;
	}
}

bool Gra::czyKoniec() //sprawdza czy dwie plansze nie sa zamrozone, jak sa zamrozone to koniec gry (jezeli nie ma bicia na dwoch)
{ 
	if ((plansze[0]->czyDaSieBic(0) == false) && (plansze[1]->czyDaSieBic(1) == false) || (plansze[0]->czyDaSieBic(0) == false) && (plansze[2]->czyDaSieBic(2) == false) || (plansze[1]->czyDaSieBic(1) == false) && (plansze[2]->czyDaSieBic(2) == false))
		return true;
	else
		return false;
}

void Gra::podliczanieDotarlych()
{
	for (int gracz = 1; gracz < 4; gracz++)
	{
		for (int i = 0; i < 3; i++) {
			int ilosc;
			ilosc=plansze[i]->ileDotarlo(gracz, i);
			switch (gracz) {
			case 1:
				liczbaPunktowGracz1 += ilosc * 3;
				break;
			case 2:
				liczbaPunktowGracz2 += ilosc * 3;
				break;
			case 3:
				liczbaPunktowGracz3 += ilosc * 3;
				break;
			}
		}
	}
}

void Gra::wyswietlaniePunktow() //wypisanie punktow
{
	cout << "#############################"<< endl;
	cout << "# Gracz 1. liczba punktow: " << liczbaPunktowGracz1 << " # " << endl;
	cout << "# Gracz 2. liczba punktow: " << liczbaPunktowGracz2 << " # " << endl;
	cout << "# Gracz 3. liczba punktow: " << liczbaPunktowGracz3 << " # " << endl;
	cout << "#############################" << endl;
}

