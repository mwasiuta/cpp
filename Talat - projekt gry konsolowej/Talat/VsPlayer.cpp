#include "VsPlayer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

VsPlayer::VsPlayer()  // dostepne pionki
{
	for (int i = 0; i < 3; i++) 
	{
		pionki[i][0] = new Pionek('T', 1, i + 1);
		pionki[i][1] = new Pionek('S', 1, i + 1);
		pionki[i][2] = new Pionek('K', 1, i + 1);
		pionki[i][3] = new Pionek('T', 2, i + 1);
		pionki[i][4] = new Pionek('S', 2, i + 1);
		pionki[i][5] = new Pionek('K', 2, i + 1);
		pionki[i][6] = new Pionek('T', 3, i + 1);
		pionki[i][7] = new Pionek('S', 3, i + 1);
		pionki[i][8] = new Pionek('K', 3, i + 1);
	}
}




void VsPlayer::ustawianiePionkow() 
{
	int wybor, wsp, ktory;
	srand(unsigned(time(NULL)));

	this->wypiszPlansze();
	for (int i = 0; i < 4; i++) // tutaj mozna zmienic liczbe pionkow jezeli chcemy przeprowadzic szybki test - domyslnie jest 9
	{
		this->wypiszPlansze();

		do 
		{
			cout << "Graczu o numerze 1, oto Twoje dostepne pionki:" << endl;
			cout << "######################################" << endl;
			for (int j = 0; j < 9; j++) 
			{
				if (pionki[0][j] != NULL) 
					cout << "# Pionek o numerze: " << j + 1 << " Poziom: " << pionki[0][j]->getPoziom() << "Typ:" << pionki[0][j]->getTyp() <<" #"<< endl;
			}
			cout << "######################################" << endl << endl;
			do 
			{
				cout << "Ktory pionek chcesz ustawic? Podaj jego numer (1-9)" << endl;
				cout << "--> ";
				while (!(cin >> ktory) || getchar() != '\n')
				{
					cout << "##################################################################" << endl;
					cout << "# Nie ma pionka o takim numerze do ustawienia! Wprowadz ponownie #" << endl;
					cout << "##################################################################" << endl << endl;
					cout << "--> ";
					cin.clear();
					cin.ignore();
				}
				ktory--;

				if (ktory < 0 || ktory >8)
				{
					cout << "##################################################################" << endl;
					cout << "# Nie ma pionka o takim numerze do ustawienia! Wprowadz ponownie #" << endl;
					cout << "##################################################################" << endl << endl;
					cout << "--> ";
					continue;
				}

				if (pionki[0][ktory] != NULL)
					break;

				cout << "##################################################################" << endl;
				cout << "# Nie ma pionka o takim numerze do ustawienia! Wprowadz ponownie #" << endl;
				cout << "##################################################################" << endl << endl;
				cout << "--> ";

			} while (1);

			do 
			{
				cout << endl;
				cout << "Podaj plansze na ktorej chcesz ustawic (1 lub 2)" << endl;
				cout << "--> ";
				while (!(cin >> wybor) || getchar() != '\n')
				{
					cout << "##########################################################" << endl;
					cout << "# Nie mozna ustawic na takiej planszy! Wprowadz ponownie #" << endl;
					cout << "##########################################################" << endl << endl;
					cout << "--> ";
					cin.clear();
					cin.ignore();
				}

				if (wybor == 1 || wybor == 2) 
					break;

				cout << "##########################################################" << endl;
				cout << "# Nie mozna ustawic na takiej planszy! Wprowadz ponownie #" << endl;
				cout << "##########################################################" << endl << endl;
				cout << "--> ";
			} while (1);

			wybor--;

			do 
			{
				cout << endl;
				cout << "Podaj wspolrzedna na ktorej chcesz ustawic (1-5)" << endl;
				cout << "--> ";
				while (!(cin >> wsp) || getchar() != '\n')
				{
					cout << "#############################################" << endl;
					cout << "# Podano zla wspolrzedna! Wprowadz ponownie #" << endl;
					cout << "#############################################" << endl << endl;
					cout << "--> ";
					cin.clear();
					cin.ignore();
				}
				if (wsp > 0 && wsp < 6)
					break;

				cout << "#############################################" << endl;
				cout << "# Podano zla wspolrzedna! Wprowadz ponownie #" << endl;
				cout << "#############################################" << endl << endl;
				cout << "--> ";
			} while (1);

			if (plansze[wybor]->dodajDoPlanszy(wsp, *pionki[0][ktory]))
				break;

			cout << "################################################" << endl;
			cout << "# Dodawanie sie nie powiodlo! Sprobuj ponownie #" << endl;
			cout << "################################################" << endl << endl;
		} while (1);


		delete pionki[0][ktory];
		pionki[0][ktory] = NULL;
		this->wypiszPlansze();


		do 
		{
			cout << "Graczu o numerze 2, oto Twoje dostepne pionki:" << endl;
			cout << "######################################" << endl;
			for (int j = 0; j < 9; j++) 
			{
				if (pionki[1][j] != NULL)
					cout << "# Pionek o numerze: " << j + 1 << " Poziom: " << pionki[1][j]->getPoziom() << "Typ:" << pionki[1][j]->getTyp() << " #" << endl;
			}

			do 
			{
				cout << "######################################" << endl << endl;
				cout << "Ktory pionek chcesz ustawic? Podaj jego numer (1-9)" << endl;
				cout << "--> ";
				while (!(cin >> ktory) || getchar() != '\n')
				{
					cout << "##################################################################" << endl;
					cout << "# Nie ma pionka o takim numerze do ustawienia! Wprowadz ponownie #" << endl;
					cout << "##################################################################" << endl << endl;
					cout << "--> ";
					cin.clear();
					cin.ignore();
				}
				ktory--;


				if (ktory < 0 || ktory >8)
				{
					cout << "##################################################################" << endl;
					cout << "# Nie ma pionka o takim numerze do ustawienia! Wprowadz ponownie #" << endl;
					cout << "##################################################################" << endl << endl;
					cout << "--> ";
					continue;
				}


				if (pionki[1][ktory] != NULL)
					break;

				cout << "##################################################################" << endl;
				cout << "# Nie ma pionka o takim numerze do ustawienia! Wprowadz ponownie #" << endl;
				cout << "##################################################################" << endl << endl;
				cout << "--> ";
			} while (1);


			do 
			{
				cout << endl;
				cout << "Podaj plansze na ktorej chcesz ustawic (2 lub 3)" << endl;
				cout << "--> ";
				while (!(cin >> wybor) || getchar() != '\n')
				{
					cout << "##########################################################" << endl;
					cout << "# Nie mozna ustawic na takiej planszy! Wprowadz ponownie #" << endl;
					cout << "##########################################################" << endl << endl;
					cout << "--> ";
					cin.clear();
					cin.ignore();
				}

				if (wybor == 3 || wybor == 2)
					break;

				cout << "##########################################################" << endl;
				cout << "# Nie mozna ustawic na takiej planszy! Wprowadz ponownie #" << endl;
				cout << "##########################################################" << endl << endl;
				cout << "--> ";
			} while (1);

			wybor--;

			do 
			{
				cout << endl;
				cout << "Podaj wspolrzedna na ktorej chcesz ustawic (21-25)" << endl;
				cout << "--> ";
				while (!(cin >> wsp) || getchar() != '\n')
				{
					cout << "#############################################" << endl;
					cout << "# Podano zla wspolrzedna! Wprowadz ponownie #" << endl;
					cout << "#############################################" << endl <<endl;
					cout << "--> ";
					cin.clear();
					cin.ignore();
				}

				if (wsp > 20 && wsp < 26)
					break;

			} while (1);


			if (plansze[wybor]->dodajDoPlanszy(wsp, *pionki[1][ktory]))
				break;
			cout << "################################################" << endl;
			cout << "# Dodawanie sie nie powiodlo! Sprobuj ponownie #" << endl;
			cout << "################################################" << endl << endl;
		} while (1);


		delete pionki[1][ktory];
		pionki[1][ktory] = NULL;
		this->wypiszPlansze();


		do 
		{
			do 
			{
				ktory = rand() % 9;
				if (pionki[2][ktory] != NULL)
					break;

			} while (1);


			do 
			{
				wybor = (rand() % 3) + 1;
				if (wybor == 1 || wybor == 3)
					break;
			} while (1);

			wybor--;

			do 
			{
				if (wybor == 0)
				{
					wsp = rand() % 5 + 21;
					break;
				}


				else if (wybor == 2) 
				{
					wsp = rand() % 5 + 1;
					break;
				}

			} while (1);

			if (plansze[wybor]->dodajDoPlanszy(wsp, *pionki[2][ktory]))
				break;
		} while (1);

		delete pionki[2][ktory];
		pionki[2][ktory] = NULL;
	}
}

void VsPlayer::rozgrywka() 
{
	this->wypiszPlansze();
	do 
	{
		if (czyKoniec())
			break;

		cout << "Tura gracza o numerze 1." << endl;
		this->interfejs(1);
		this->wypiszPlansze();

		if (czyKoniec()) // tu tez
			break;

		cout << "Tura gracza o numerze 2." << endl;
		this->interfejs(2);
		this->wypiszPlansze();

		if (czyKoniec())
			break;
		this->interfejsPC();
		this->wypiszPlansze();
	} while (1);
	podliczanieDotarlych();
	cout << "KONIEC GRY!" << endl;
}

void VsPlayer::interfejsPC() 
{
	int numer, co, gdzie, naKtorejPlanszy;
	srand(unsigned(time(NULL)));
	while (1) {
		if (rand() % 2 == 0)
			naKtorejPlanszy = 1;
		else
			naKtorejPlanszy = 3;
		naKtorejPlanszy--;
		if (plansze[naKtorejPlanszy]->czyDaSieBic(naKtorejPlanszy) == false) {
			continue;
		}
		numer = rand() % 25 + 1;
		if (plansze[naKtorejPlanszy]->sprawdzCzyDotarl(numer, 3, naKtorejPlanszy)) {
			continue;
		}
		co = rand() % 2 + 1;
		if (co == 1) {
			gdzie = rand() % 3 + 1;
			if (plansze[naKtorejPlanszy]->idz(numer, gdzie, 3, naKtorejPlanszy))
				break;
		}
		else if (co == 2) {
			gdzie = rand() % 5 + 1;
			if (plansze[naKtorejPlanszy]->atakuj(numer, gdzie, 3, naKtorejPlanszy)) {
				liczbaPunktowGracz3 += 5;
				break;
			}

		}
	}
}

