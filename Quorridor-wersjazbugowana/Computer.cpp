#include "Computer.h"
#include <iostream>
#include <time.h>

using namespace std;

void Computer::start() {
	bool koniec = true;
	while (koniec) {
		wyswietl();
		cout << "Gracz 1" << endl;
		tura(1);
		if (czyKoniec()) {
			koniec = false;
		}
		turaPC();
		if (czyKoniec()) {
			koniec = false;
		}
	}
	cout << "Dziekuje za gre!" << endl;
}

void Computer::turaPC() {

	srand(time(NULL));
	int co, wsp1, wsp2, koniec = 1;
	while (koniec == 1) {
		co = rand() % 2;
		switch (co) {
		case 1:
			wsp1 = rand() % 81;
			if (chodzenie(wsp1, 2))
			{
				koniec = 0;
			}
			break;
		case 2:
			wsp1 = rand() % 81;
			switch (rand() % 2) {
			case 0:
				wsp2 = wsp1 + 9;
				break;
			case 1:
				wsp2 = wsp1 - 1;
				break;
			}
			if (scianyg2 > 0) {
				if (sciana(wsp1, wsp2)) {
					scianyg2--;
					koniec = 0;
					break;
				}
			}
		}
	}
}