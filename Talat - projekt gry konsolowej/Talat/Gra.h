#pragma once
#include "Plansza.h"

class Gra
{
protected:
	int liczbaPunktowGracz1;
	int liczbaPunktowGracz2;
	int liczbaPunktowGracz3;
	Plansza *plansze[3];
	Pionek *pionki[3][9];


public:
	Gra *nast;
	virtual void ustawianiePionkow() {};
	void wypiszPlansze();
	virtual void rozgrywka() {}
	void podliczanieDotarlych();
	void interfejs(int gracz);
	bool czyKoniec();
	void wyswietlaniePunktow();
	int getpunkty3();
	int getpunkty2();
	int getpunkty1();
	Gra();
	~Gra();
};
