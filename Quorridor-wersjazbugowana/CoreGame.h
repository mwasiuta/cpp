#pragma once
#include "Field.h"
class CoreGame
{
protected:
	Field *plansza[81];
	int scianyg1;
	int scianyg2;
public:
	CoreGame();
	~CoreGame();
	void tura();
	void wyswietl();
	bool czyKoniec();
	bool sciana(int gdzie1, int gdzie2);
	bool chodzenie( int wktora, int gracz);
	virtual void rozgrywka(){}
	int gdziePionek(int gracz);
	void tura(int gracz);
	bool sprawdzanie();
	virtual void start();
};

