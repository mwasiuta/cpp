#include "Pionek.h"

Pionek::Pionek(char typ1, int poziom1, int czyj1) : typ(typ1), poziom(poziom1), czyj(czyj1) //inicjalizatory
{
}

char Pionek::getTyp()
{ 
	return typ;
}


int Pionek::getPoziom() 
{
	return poziom;
}


int Pionek::getCzyj() 
{
	return czyj;
}


Pionek::~Pionek()
{
}
