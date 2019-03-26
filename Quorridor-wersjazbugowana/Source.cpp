#include <cstdio>
#include <math.h>
#include <iostream>
#include "CoreGame.h"
#include "Player.h"
#include "Computer.h"
#include <fstream>
#include <windows.h>
#include <string.h>

using namespace std;

template <class Typ>
Typ DajCzas()
{
	SYSTEMTIME nowy;
	GetLocalTime(&nowy);
	return nowy;
}

int main() {
	int tryb;
	CoreGame *gra = NULL;
	fstream logiczyt ("logi.txt", ios::in);
	char podane[400];
	SYSTEMTIME st;
	fstream logi("logi.txt", ios::out | ios::app);
	if (logi.good() == true ) {
		cout << "Otwarto plik z logami! Ostatnie logi:" << endl;
		do {
			logiczyt.getline(podane, 400);
			cout << podane << endl;
		} while (logiczyt.eof() != true);
		st = DajCzas<SYSTEMTIME>();
		logi << st.wYear << "/" << st.wMonth << "/" << st.wDay << "  " << st.wHour << "::" << st.wMinute << "::" << st.wSecond << " Poprawnie otworzono plik z logami. Poczatek programu" << endl;
	}
	else{
		cout << "Pliku z logami nie otwarto! Koniec programu" << endl;
		return 0;
	}
	
	
	cout << "Mozesz grac we dwoch lub kontra komputer. Kazdy gracz ma 10 scianek Wpisz aby zagrac: 1- dwoch graczy 2- jeden gracz" << endl;
	
	
	while (!(cin >> tryb) || tryb<1 || tryb>2 || getchar() != '\n') {
		cout << "ERROR! Wprowadz ponownie" << endl;
		cin.clear();
		cin.ignore( '\n');
	}
	if (tryb == 1)
	{
		st = DajCzas<SYSTEMTIME>();
		logi << st.wYear << "/" << st.wMonth << "/" << st.wDay << "  " << st.wHour << "::" << st.wMinute << "::" << st.wSecond << " Wybrano tryb gry nr 1" << endl;
		gra = new Player();
	}
	else if (tryb == 2)
	{
		st = DajCzas<SYSTEMTIME>();
		logi << st.wYear << "/" << st.wMonth << "/" << st.wDay << "  " << st.wHour << "::" << st.wMinute << "::" << st.wSecond << "Wybrano tryb gry nr 2" << endl;
		gra = new Computer();
	}
	gra->wyswietl();
	st = DajCzas<SYSTEMTIME>();
	logi << st.wYear << "/" << st.wMonth << "/" << st.wDay << "  " << st.wHour << "::" << st.wMinute << "::" << st.wSecond << " Start rozgrywki" << endl;
	gra->start();
	st = DajCzas<SYSTEMTIME>();
	logi << st.wYear << "/" << st.wMonth << "/" << st.wDay << "  " << st.wHour << "::" << st.wMinute << "::" << st.wSecond << " Koniec gry" << endl;
	delete gra;
	st = DajCzas<SYSTEMTIME>();
	logi << st.wYear << "/" << st.wMonth << "/" << st.wDay << "  " << st.wHour << "::" << st.wMinute << "::" << st.wSecond << " Koniec programu" << endl;
	logi.close();
}