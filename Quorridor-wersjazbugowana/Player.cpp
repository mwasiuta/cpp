#include "Player.h"
#include <iostream>
using namespace std;

void Player::start() {
	bool koniec = true;
	while (koniec) {
		wyswietl();
		cout << "Gracz 1" << endl;
		tura(1);
		if (czyKoniec()) {
			break;
		}
		wyswietl();
		cout << "Gracz 2" << endl;
		tura(2);
		if (czyKoniec()) {
			koniec = false;
		}
	}
	cout << "Dziekuje za gre!" << endl;
}
