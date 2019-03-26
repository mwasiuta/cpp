#pragma once

class Pionek
{
private:
	char typ; // K- kwadrat, T- trojkat, S-Szesciokat
	int poziom; // 1 - maly, 2 - sredni, 3 - duzy
	int czyj; // 1- gracz pierwszy, 2 - gracz drugi , 3 - gracz trzeci

public:
	Pionek(char typ, int poziom, int czyj);
	char getTyp();
	int getPoziom();
	int getCzyj();
	~Pionek();
};

