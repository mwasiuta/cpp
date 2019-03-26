#include "Plansza.h"
#include <iostream>
#include <math.h>
using namespace std;


Plansza::Plansza() // domyslnie pola na planszy sa nullami, jesli nie jest nullem to znaczy ze cos tam stoi
{
	for (int i = 0; i < 25; i++)
	{
		tb[i] = NULL;
	}
}


Plansza::~Plansza()
{
}

void Plansza::wyswietlPlansze() {
	for (int j = 0; j < 25; j++) {
		if (tb[j] != NULL) {
			cout << "  |" << j + 1 << "|G" << tb[j]->getCzyj() << "P" << tb[j]->getPoziom() << tb[j]->getTyp() << "  ";
		}
		else
			cout << "    |" << j + 1 << "|    ";
		if (j % 5 == 4) {
			cout << "\n--------------------------------------------------------------------------------" << endl;
		}

	}
}

bool Plansza::dodajDoPlanszy(int wsp1, Pionek &dodawany) // dodawanie pionka do planszy z listy pionkow do wybrania w rozstawianiu
{
	wsp1--;
	if (tb[wsp1] == NULL) {
		tb[wsp1] = new Pionek(dodawany.getTyp(), dodawany.getPoziom(), dodawany.getCzyj());
		return true;
	}
	return false;
}

bool Plansza::idz(int numer, int gdzie, int gracz, int naKtorejPlanszy) {
	numer--;
	if (numer % 5 == 0 && gdzie == 2 || numer % 5 == 4 && gdzie == 3) // aby pionek nie mogl wyjsc zza plansze
		return false;


	switch (naKtorejPlanszy)  // na kazdej planszy jest inaczej, np. na planszy nr 1. gracz 3 jest od dolu a na trzeciej od gory funkcja mowi jak ma sie zachowac dalej, gdzie to najpierw jest wybor gracza 1. przod 2. lewy skos 3. prawy skos, a potem tlumaczy jak przeksztalcic

	{
	default:
		return false;

	case 0:// plansza 1
		switch (gracz) {
		default:
			return false;
		case 1: // gracz 1
			switch (gdzie) {
			default:
				return false;
			case 1:
				gdzie = numer + 5;
				break;
			case 2:
				gdzie = numer + 4;
				break;
			case 3:
				gdzie = numer + 6;
				break;
			}
			break;

		case 2: // gracz 2
			return false;
		case 3: // gracz 3
			switch (gdzie) {
			default:
				return false;
			case 1:
				gdzie = numer - 5;
				break;
			case 2:
				gdzie = numer - 6;
				break;
			case 3:
				gdzie = numer - 4;
				break;
			}
			break;
		}
		break;
	case 1: // 2 plansza
		switch (gracz) {
		default:
			return false;
		case 1: // gracz 1
			switch (gdzie) {
			default:
				return false;
			case 1:
				gdzie = numer + 5;
				break;
			case 2:
				gdzie = numer + 4;
				break;
			case 3:
				gdzie = numer + 6;
				break;
			}
			break;

		case 2:
			switch (gdzie) {
			default:
				return false;
			case 1:
				gdzie = numer - 5;
				break;
			case 2:
				gdzie = numer - 6;
				break;
			case 3:
				gdzie = numer - 4;
				break;
			}
			break;
		case 3:
			return false;
		}
		break;


	case 2: // 3 plansza
		switch (gracz) {
		default:
			return false;
		case 1: // gracz 1
			return false;

		case 2:
			switch (gdzie) {
			default:
				return false;
			case 1:
				gdzie = numer - 5;
				break;
			case 2:
				gdzie = numer - 6;
				break;
			case 3:
				gdzie = numer - 4;
				break;
			}
			break;
		case 3:
			switch (gdzie) {
			default:
				return false;
			case 1:
				gdzie = numer + 5;
				break;
			case 2:
				gdzie = numer + 4;
				break;
			case 3:
				gdzie = numer + 6;
				break;
			}
			break;
		}
		break;


	}
	if (tb[numer] != NULL && tb[gdzie] == NULL && tb[numer]->getCzyj() == gracz)  // zabezpiecznie zeby ruszac tylko swoim pionkiem i ustawiac pionki w odpowiednie miejsce
	{
		tb[gdzie] = tb[numer];
		tb[numer] = NULL; // usuniecie miejsca(adresu)
		return true;
	}
	return false;
}

bool Plansza::atakuj(int numer, int gdzie, int gracz, int naKtorejPlanszy) // podobnie jak w metodzie idz
{
	numer--;
	if (numer % 5 == 0 && (gdzie == 2 || gdzie == 4) || numer % 5 == 4 && (gdzie == 3 || gdzie == 5))
		return false;
	switch (naKtorejPlanszy) {
	default:
		return false;

	case 0:// plansza 1
		switch (gracz) {
		default:
			return false;
		case 1: // gracz 1
			switch (gdzie) {
			default:
				return false;
			case 1:
				gdzie = numer + 5;
				break;
			case 2:
				gdzie = numer + 4;
				break;
			case 3:
				gdzie = numer + 6;
				break;
			case 4:
				gdzie = numer - 1;
				break;
			case 5:
				gdzie = numer + 1;
				break;
			}
			break;

		case 2:
			return false;
		case 3:
			switch (gdzie) {
			default:
				return false;
			case 1:
				gdzie = numer - 5;
				break;
			case 2:
				gdzie = numer - 6;
				break;
			case 3:
				gdzie = numer - 4;
				break;
			case 4:
				gdzie = numer - 1;
				break;
			case 5:
				gdzie = numer + 1;
				break;
			}
			break;
		}
		break;
	case 1: // 2 plansza
		switch (gracz) {
		default:
			return false;
		case 1: // gracz 1
			switch (gdzie) {
			default:
				return false;
			case 1:
				gdzie = numer + 5;
				break;
			case 2:
				gdzie = numer + 4;
				break;
			case 3:
				gdzie = numer + 6;
				break;
			case 4:
				gdzie = numer - 1;
				break;
			case 5:
				gdzie = numer + 1;
				break;
			}
			break;

		case 2:
			switch (gdzie) {
			default:
				return false;
			case 1:
				gdzie = numer - 5;
				break;
			case 2:
				gdzie = numer - 6;
				break;
			case 3:
				gdzie = numer - 4;
				break;
			case 4:
				gdzie = numer - 1;
				break;
			case 5:
				gdzie = numer + 1;
				break;
			}
			break;
		case 3:
			return false;
		}
		break;


	case 2: // 3 plansza
		switch (gracz) {
		default:
			return false;
		case 1: // gracz 1
			return false;

		case 2:
			switch (gdzie) {
			default:
				return false;
			case 1:
				gdzie = numer - 5;
				break;
			case 2:
				gdzie = numer - 6;
				break;
			case 3:
				gdzie = numer - 4;
				break;
			case 4:
				gdzie = numer - 1;
				break;
			case 5:
				gdzie = numer + 1;
				break;
			}
			break;
		case 3:
			switch (gdzie) {
			default:
				return false;
			case 1:
				gdzie = numer + 5;
				break;
			case 2:
				gdzie = numer + 4;
				break;
			case 3:
				gdzie = numer + 6;
				break;
			case 4:
				gdzie = numer - 1;
				break;
			case 5:
				gdzie = numer + 1;
				break;
			}
			break;
		}
		break;


	}
	if (tb[numer] != NULL && tb[gdzie] != NULL && tb[numer]->getCzyj() == gracz && tb[gdzie]->getCzyj() != gracz)
	{
		if (sprzawdzAtak(numer, gdzie)) // czy mozliwy jest atak
		{
			delete tb[gdzie]; // zwalniam pamiec tam gdzie zaatakowalem
			tb[gdzie] = tb[numer];// jezeli pionek zostal zbity to pionek przechodzi w to miejsce
			tb[numer] = NULL;// zwalniam wczesniejsze miejsce z ktorego atakowalem
			return true;
		}
	}
	return false; // jezeli sie nie uda
}

int Plansza::ileDotarlo(int gracz, int ktora) // funkcja liczy ile pionkow dotarlo na mete za pomoca innej funkcji
{
	int ilosc = 0;
	for (int i = 0; i < 25; i++) {
		if (tb[i] != NULL && tb[i]->getCzyj() == gracz) {
			if (sprawdzCzyDotarl(i, gracz, ktora))
				ilosc++;
		}
	}
	return ilosc;
}

bool Plansza::czyDaSieBic(int naKtorejPlanszy) 
{ 
	for (int numer = 0; numer < 25; numer++) // sprawdzam dla kazdego pola
	{ 
		if (tb[numer] != NULL) // jesli to pole nie jest nullem
		{ 
			switch (naKtorejPlanszy) // to sprawdzam na jakiej jest planszy
			{ 
			case 0: // plansza 1
				switch (tb[numer]->getCzyj()) // czyjego gracza to pionek (do tylu bic nie mozna i tez jest roznie ustawione - gracz ustawiony albo od gory albo od dolu)
				{ 
				case 1: // gracaz 1

					if (numer % 5 != 0) { // tutaj sprawdzm bicie w bok
						if (sprzawdzAtak(numer, numer - 1))
							return true;
					}
					if (numer % 5 != 4) {// tutaj sprawdzm bicie w bok
						if (sprzawdzAtak(numer, numer + 1))
							return true;
					}
					for (int j = numer; j<25; j += 4) { // ide w lewo po skosie
						for (int i = j; i < 25; i += 5) { // sprawdzam wszystkie w dol poczawszy od tego na gorze
							if (sprzawdzAtak(numer, i)) // czy da sie bic, jestli tak to true i nie jest zamrozona
								return true;

						}
						if (j % 5 == 0)
							break;
					}

					for (int j = numer; j<25; j += 6) { // w prawo po skosie
						for (int i = j; i < 25; i += 5) {// sprawdzam atak
							if (sprzawdzAtak(numer, i))
								return true;

						}
						if (j % 5 == 4)
							break;
					}
					break;

				case 2:
					break;
				case 3:
					if (numer % 5 != 0) {
						if (sprzawdzAtak(numer, numer - 1))
							return true;
					}
					if (numer % 5 != 4) {
						if (sprzawdzAtak(numer, numer + 1))
							return true;
					}
					for (int j = numer; j >= 0; j -= 4) { // patrzac od dolu (dla gracza od dolu )
						for (int i = j; i >= 0; i -= 5) { // tak samo tylko ze w gore
							if (sprzawdzAtak(numer, i))
								return true;

						}
						if (j % 5 == 4)
							break;
					}

					for (int j = numer; j >= 0; j -= 6) {
						for (int i = j; i >= 0; i -= 5) {
							if (sprzawdzAtak(numer, i))
								return true;

						}
						if (j % 5 == 0)
							break;
					}
					break;
				}
				break;
			case 1:
				switch (tb[numer]->getCzyj()) {
				case 1:
					if (numer % 5 != 0) {
						if (sprzawdzAtak(numer, numer - 1))
							return true;
					}
					if (numer % 5 != 4) {
						if (sprzawdzAtak(numer, numer + 1))
							return true;
					}
					for (int j = numer; j<25; j += 4) {
						for (int i = j; i < 25; i += 5) {
							if (sprzawdzAtak(numer, i))
								return true;

						}
						if (j % 5 == 0)
							break;
					}

					for (int j = numer; j<25; j += 6) {
						for (int i = j; i < 25; i += 5) {
							if (sprzawdzAtak(numer, i))
								return true;

						}
						if (j % 5 == 4)
							break;
					}
					break;
				case 2:
					if (numer % 5 != 0) {
						if (sprzawdzAtak(numer, numer - 1))
							return true;
					}
					if (numer % 5 != 4) {
						if (sprzawdzAtak(numer, numer + 1))
							return true;
					}
					for (int j = numer; j >= 0; j -= 4) {
						for (int i = j; i >= 0; i -= 5) {
							if (sprzawdzAtak(numer, i))
								return true;

						}
						if (j % 5 == 4)
							break;
					}

					for (int j = numer; j >= 0; j -= 6) {
						for (int i = j; i >= 0; i -= 5) {
							if (sprzawdzAtak(numer, i))
								return true;

						}
						if (j % 5 == 0)
							break;
					}
					break;
				case 3:
					break;
				}
				break;

			case 2:
				switch (tb[numer]->getCzyj()) {
				case 1:
					return false;
				case 2:
					if (numer % 5 != 0) {
						if (sprzawdzAtak(numer, numer - 1))
							return true;
					}
					if (numer % 5 != 4) {
						if (sprzawdzAtak(numer, numer + 1))
							return true;
					}
					for (int j = numer; j >= 0; j -= 4) {
						for (int i = j; i >= 0; i -= 5) {
							if (sprzawdzAtak(numer, i))
								return true;

						}
						if (j % 5 == 4)
							break;
					}

					for (int j = numer; j >= 0; j -= 6) {
						for (int i = j; i >= 0; i -= 5) {
							if (sprzawdzAtak(numer, i))
								return true;

						}
						if (j % 5 == 0)
							break;
					}
					break;
				case 3:
					if (numer % 5 != 0) {
						if (sprzawdzAtak(numer, numer - 1))
							return true;
					}
					if (numer % 5 != 4) {
						if (sprzawdzAtak(numer, numer + 1))
							return true;
					}
					for (int j = numer; j<25; j += 4) {
						for (int i = j; i < 25; i += 5) {
							if (sprzawdzAtak(numer, i))
								return true;

						}
						if (j % 5 == 0)
							break;
					}

					for (int j = numer; j<25; j += 6) {
						for (int i = j; i < 25; i += 5) {
							if (sprzawdzAtak(numer, i))
								return true;

						}
						if (j % 5 == 4)
							break;
					}
					break;
				}
				break;
			}
		}

	}
	return false;

}

bool Plansza::sprzawdzAtak(int numer, int gdzie) { // czy pionek z [numer] moze zbic pionek z [gdzie]
	if (tb[gdzie] == NULL)
		return false;

	if (tb[numer]->getCzyj() == tb[gdzie]->getCzyj()) // zeby nie mozna zbic swojego
		return false;

	if (tb[numer]->getPoziom() == (tb[gdzie]->getPoziom() + 1) || tb[numer]->getPoziom() == 1 && tb[numer]->getTyp() == 'T' && tb[gdzie]->getPoziom() == 3 && tb[gdzie]->getTyp() == 'S' || tb[numer]->getPoziom() == tb[gdzie]->getPoziom() && tb[numer]->getTyp() == 'S' && (tb[gdzie]->getTyp() == 'T' || tb[gdzie]->getTyp() == 'K') || tb[numer]->getPoziom() == tb[gdzie]->getPoziom() && tb[numer]->getTyp() == 'K' && tb[gdzie]->getTyp() == 'T') {
		return true; //wyzej warunki z zasad
	}
	else
		return false;
}

bool Plansza::sprawdzCzyDotarl(int numer, int gracz, int naKtorejPlanszy) { // sprawdzenie czy dotarl do mety
	switch (naKtorejPlanszy) { 
	case 0://plansza 1
		switch (gracz) {
		case 1:
			if (numer >= 21 && numer <= 25)
				return true;
			break;
		case 2:
			return false;
		case 3:
			if (numer > 0 && numer <= 5)
				return true;
			break;
		}
	case 1:
		switch (gracz) {
		case 1:
			if (numer >= 21 && numer <= 25)
				return true;
			break;
		case 2:
			if (numer > 0 && numer <= 5)
				return true;
			break;
		case 3:
			return false;
			break;
		}

	case 2:
		switch (gracz) {
		case 1:
			return false;
			break;
		case 2:
			if (numer >= 1 && numer <= 5)
				return true;
			break;
		case 3:
			if (numer >= 21 && numer <= 25)
				return true;
			break;
		}

	default:
		return false;

	}
	return false;
}