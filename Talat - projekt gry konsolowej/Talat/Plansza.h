#pragma once
#include "Pionek.h"

class Plansza
{
private:
	Pionek *tb[25];  // tablica pionkow


public:
	bool czyDaSieBic(int naKtorejPlanszy);
	void wyswietlPlansze();
	bool dodajDoPlanszy(int wsp1, Pionek &dodawany);
	bool atakuj(int numer, int gdzie, int gracz, int naKtorejPlanszy);
	bool idz(int numer, int gdzie, int gracz, int naKtorejPlanszy);
	int ileDotarlo(int gracz, int ktora);
	bool sprawdzCzyDotarl(int numer, int gracz, int naKtorejPlanszy);
	bool sprzawdzAtak(int numer, int gdzie);
	Plansza();
	~Plansza();
};

