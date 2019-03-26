#include "CoreGame.h"
#include <cstdlib>
#include <iostream>
#include <math.h>
#include "Field.h"

using namespace std;
CoreGame::CoreGame(): scianyg1(10), scianyg2(10)
{
	for (int i = 0; i < 81; i++) {
		plansza[i] = new Field(i);
	}
	plansza[36]->setKogo(1);
	plansza[44]->setKogo(2);

}

CoreGame::~CoreGame() {
	for (int i = 0; i < 81; i++) {
		delete plansza[i];
	}
}

void CoreGame::wyswietl() {
	system("cls");
	for (int i = 0; i < 81; i+=9) {
		
		for (int j = i; j < i + 9; j++) {
			if (plansza[j]->getGora() == false)
				cout << " _______ ";
			else
				cout << "         ";
		}
		cout << endl;

		for (int j = i; j < i + 9; j++)
		{

			if (plansza[j]->getLewo() == false) {
				cout << "|";
			}
			else
				cout << " ";

			if (plansza[j]->getKogo() == 0)
			{
				cout << "  ";
				if (j < 10)
					cout << " ";
				cout<<j<<"  ";
			}
			else if (plansza[j]->getKogo() == 1) {
				cout << "  G1  ";
			}
			else if (plansza[j]->getKogo() == 2) {
				cout << "  G2  ";
			}
			if (plansza[j]->getPrawo() == false)
				cout << "|";
			else
				cout << "  ";
		}
		cout << endl;
		for (int j = i; j < i + 9; j++) {
			if (plansza[j]->getDol() == false)
				cout << " _______ ";
			else
				cout << "         ";
		}
		cout << endl;
		cout << "\n------------------------------------------------------------------------------------" << endl;
	}
}

void CoreGame::tura(int gracz) {
	int co, wsp1, wsp2, koniec=1;
	while (koniec==1){
		cout << "Co chcesz zrobic? 1. chodzenie 2. stawianie sciany" << endl;
		while (!(cin >> co) || getchar() != '\n') {
			cout << "ERROR! Wprowadz ponownie" << endl;
			cin.clear();
			cin.ignore(numeric_limits < streamsize >::max(), '\n');
		}
		switch (co) {
		default:
			cout << "Cos poszlo nie tak! Wprowadz ponownie" << endl;
			break;
		case 1:
			cout << "Na jakie pole chcesz sie przemiescic (mozesz przeskakiwac pionek przeciwnika w dowolna strone)" << endl;
			while (!(cin >> wsp1) || getchar() != '\n') {
				cout << "ERROR! Wprowadz ponownie" << endl;
				cin.clear();
				cin.ignore(numeric_limits < streamsize >::max(), '\n');
			}
			if (chodzenie(wsp1, gracz))
			{
				cout << "Przemieszczono pionek" << endl;
				koniec = 0;
			}
			else
			{
				cout << "Blad! Sprobuj ponownie" << endl;
			}
			break;
		case 2:
			if (gracz == 1 && scianyg1 == 0) {
				cout << "Nie masz juz scianek!" << endl;
				break;
			}
			if (gracz == 2 && scianyg2 == 0)
			{
				cout << "Nie masz juz scianek!" << endl;
				break;
			}
			cout << "Na jakich polach chcesz ustawic scianke? Scianke mozesz ustawic po prawej lub u gory dwoch pol (w zaleznosci od podanych pol)." << endl;
			cout << "Nie mozesz zablokowac swojego przeciwnika calkowicie. Pola musza byc obok siebie. Masz jeszcze ";
			if (gracz == 1)
				cout << scianyg1;
			else
				cout << scianyg2;
			cout << " scianek" << endl;
			cout << "Podaj pierwsza wspolrzedna:" << endl;
			while (!(cin >> wsp1) || getchar() != '\n') {
				cout << "ERROR! Wprowadz ponownie" << endl;
				cin.clear();
				cin.ignore(numeric_limits < streamsize >::max(), '\n');
			}
			cout << "Podaj druga wspolrzedna:" << endl;
			while (!(cin >> wsp2) || getchar() != '\n') {
				cout << "ERROR! Wprowadz ponownie" << endl;
				cin.clear();
				cin.ignore(numeric_limits < streamsize >::max(), '\n');
			}
			if (gracz == 1) {
				if (scianyg1 > 0) {
					if (sciana(wsp1, wsp2)) {
						cout << "Postawiono sciane" << endl;
						scianyg1--;
						koniec = 0;
						break;
					}
					else
					{
						cout << "Blad! sprobuj ponownie" << endl;
						break;
					}
				}
				else
					cout << "Nie masz juz scian!" << endl;
			}
			else if (gracz == 2) {
				if (scianyg2 > 0) {
					if (sciana(wsp1, wsp2)) {
						cout << "Postawiono sciane" << endl;
						scianyg2--;
						koniec = 0;
						break;
					}
				}
				else
					cout << "Nie masz juz scian!" << endl;
			}
			else
			{
				cout << "Cos poszlo nie tak! Wprowadz ponownie" << endl;
			}
		}
	}
}

bool CoreGame::czyKoniec() {
	for (int i = 0; i < 81; i += 9)
	{
		if (plansza[i]->getKogo() == 2)
			return true;
	}
	for (int i = 8; i < 81; i += 9)
	{
		if (plansza[i]->getKogo() == 1) {
			return true;
		}
	}
	return false;
}

bool CoreGame::sciana(int gdzie1, int gdzie2) { // podaj pola u gory ktorych chcesz ustawic scianke, lub pola po prawej od ktorych chcesz ustawic scianke
	if (gdzie1 < 0 || gdzie1 >80 || gdzie2<0 || gdzie2>80)
		return false;
	if (gdzie1 == gdzie2)
		return false;

	if ( gdzie1>8 && gdzie1 == gdzie2 - 9 || gdzie1 < 72 && gdzie1 == gdzie2 + 9) {
		if (plansza[gdzie1]->getPrawo() == false || plansza[gdzie2]->getPrawo() == false)
			return false;
		if (gdzie2 < gdzie1 && plansza[gdzie2]->getDol() == false && plansza[gdzie2 + 1]->getDol() == false) {
			return false;
		}
		else if (gdzie1 < gdzie2 && plansza[gdzie1]->getDol() == false && plansza[gdzie1 + 1]->getDol() == false)
			return false;
		plansza[gdzie1]->setPrawo(false);
		plansza[gdzie2]->setPrawo(false);
		plansza[gdzie1 + 1]->setLewo(false);
		plansza[gdzie2 + 1]->setLewo(false);
		if (sprawdzanie())
			return true;
		else
		{
			plansza[gdzie1]->setPrawo(true);
			plansza[gdzie2]->setPrawo(true);
			plansza[gdzie1 + 1]->setLewo(true);
			plansza[gdzie2 + 1]->setLewo(true); 
			return false;
		}
	}
	if (gdzie1%9!=8 && gdzie1 == gdzie2 + 1 || gdzie1%9!=0 && gdzie1 == gdzie2 - 1) { // gdzie1%9 != 8 && gdzie1 == gdzie2 + 1 || gdzie1 = gdzie2 - 1 && gdzie1 % 9 != 0
		if (plansza[gdzie1]->getGora() == false || plansza[gdzie2]->getGora() == false) {
			return false;
		}
		if (gdzie1 < gdzie2 && plansza[gdzie1]->getPrawo() == false && plansza[gdzie1 - 9]->getPrawo() == false)
			return false;
		else if (gdzie1 > gdzie2 && plansza[gdzie2]->getPrawo() == false && plansza[gdzie2 - 9]->getPrawo() == false)
			return false;
		plansza[gdzie1]->setGora(false);
		plansza[gdzie2]->setGora(false);
		plansza[gdzie1 - 9]->setDol(false);
		plansza[gdzie2 - 9]->setDol(false);
		if (sprawdzanie())
			return true;
		else
		{
			plansza[gdzie1]->setGora(true);
			plansza[gdzie2]->setGora(true);
			plansza[gdzie1 - 9]->setDol(true);
			plansza[gdzie2 - 9]->setDol(true);
		}
	}
}

bool CoreGame::chodzenie(int pole, int gracz) {
	int skad = gdziePionek(gracz);//  1 - prosto 2 - tyl 3 - gora 4- dol
	if (plansza[pole]->getKogo() != 0)
		return false;
	
	if (skad == pole + 1 && plansza[skad]->getLewo()==true) {
		plansza[skad]->setKogo(0);
		plansza[pole]->setKogo(gracz);
		return true;
	}
	else if (skad == pole - 1 && plansza[skad]->getPrawo() == true ) {
		plansza[skad]->setKogo(0);
		plansza[pole]->setKogo(gracz);
		return true;
	}
	else if (skad == pole + 9 && plansza[skad]->getGora() == true) {
		plansza[skad]->setKogo(0);
		plansza[pole]->setKogo(gracz);
		return true;
	}
	else if (skad == pole - 9 && plansza[skad]->getDol() == true ) {
		plansza[skad]->setKogo(0);
		plansza[pole]->setKogo(gracz);
		return true;
	}
	else if (skad == pole - 18 && plansza[skad]->getDol() == true && plansza[skad + 9]->getKogo() != 0 && plansza[skad + 9]->getDol() == true || skad == pole - 10 && plansza[skad]->getDol() == true && plansza[skad + 9]->getKogo() != 0 && plansza[skad + 9]->getPrawo() == true || skad == pole - 8 && plansza[skad]->getDol() == true && plansza[skad + 9]->getKogo() != 0 && plansza[skad + 9]->getLewo() == true) {
		plansza[skad]->setKogo(0);
		plansza[pole]->setKogo(gracz);
		return true;
	}
	else if (skad == pole + 18 && plansza[skad]->getGora() == true && plansza[skad - 9]->getKogo() != 0 && plansza[skad - 9]->getGora() == true || skad == pole + 10 && plansza[skad]->getGora() == true && plansza[skad - 9]->getKogo() != 0 && plansza[skad - 9]->getLewo() == true || skad == pole + 8 && plansza[skad]->getGora() == true && plansza[skad - 9]->getKogo() != 0 && plansza[skad - 9]->getPrawo() == true)
	{
		plansza[skad]->setKogo(0);
		plansza[pole]->setKogo(gracz);
		return true;
	}
	else if (skad == pole - 2 && plansza[skad]->getPrawo() == true && plansza[skad + 1]->getKogo() != 0 && plansza[skad + 1]->getPrawo() == true || skad == pole + 8 && plansza[skad]->getPrawo() == true && plansza[skad + 1]->getKogo() != 0 && plansza[skad + 1]->getGora() == true || skad == pole - 10 && plansza[skad]->getPrawo() == true && plansza[skad + 1]->getKogo() != 0 && plansza[skad + 1]->getDol() == true)
	{
		plansza[skad]->setKogo(0);
		plansza[pole]->setKogo(gracz);
		return true;
	}
	else if (skad == pole + 2 && plansza[skad]->getLewo() == true && plansza[skad - 1]->getKogo() != 0 && plansza[skad - 1]->getLewo() == true || skad == pole + 10 && plansza[skad]->getLewo() == true && plansza[skad - 1]->getKogo() != 0 && plansza[skad - 1]->getGora() == true || skad == pole - 8 && plansza[skad]->getLewo() == true && plansza[skad - 1]->getKogo() != 0 && plansza[skad - 1]->getDol() == true) {
		plansza[skad]->setKogo(0);
		plansza[pole]->setKogo(gracz);
		return true;
	}
	return false;

}
int CoreGame::gdziePionek(int gracz) {
	for (int i = 0; i < 81; i++) {
		if (plansza[i]->getKogo()== gracz)
			return i;
	}
	return 0;
}

bool CoreGame::sprawdzanie() {
	return true;
}

void CoreGame::start()
{
}

