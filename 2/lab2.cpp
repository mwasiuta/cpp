#include <math.h>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

struct stos {
	string wartosc;
	stos *nast;
};

void funkcja(fstream &plik) {
	stos *glowa = new stos;
	stos *wsk = glowa;
	string pomocnicza;
	int msupopen = 0;
	int mrowopen = 0;
	int fencedopen = 0;
	getline(plik, glowa->wartosc);
	pomocnicza = glowa->wartosc;
	try {
		if (pomocnicza[pomocnicza.length() - 1] != '>' || pomocnicza[0] != '<' || pomocnicza[1] != 'm' || pomocnicza[2] != 'a' || pomocnicza[3] != 't' || pomocnicza[4] != 'h')
		{
			throw 0;
		}
	}
	catch (int blad) {
		if (blad == 0)
		{
			cout << "Nie otwarto wyrazenia, id bledu: " << blad << endl;
			return;
		}
	}
	while (1) {
		wsk->nast = new stos;
		*wsk = *wsk->nast;
		getline(plik, wsk->wartosc);
		pomocnicza=wsk->wartosc;
		try {

			if (plik.eof() == true && msupopen == 1 || plik.eof() == true && mrowopen == 1 || plik.eof() == true && fencedopen == 1)
				throw 15;
			if (plik.eof() == true && pomocnicza != "</math>") {
				throw 1;
			}
			else if (plik.eof() == true) break;
			// msup
			if (pomocnicza == "<msup>" && msupopen == 1) {
				throw 5;
			}
			else if (pomocnicza == "<msup>") {
				msupopen = 1;
				continue;
			}
			
			if (pomocnicza == "</msup>" && msupopen == 1) {
				msupopen = 0;
				continue;
			}
			else if (pomocnicza == "</msup>")
				throw 6;

			// mfenced
			if (pomocnicza == "<mfenced>" && fencedopen==1) {
				throw 10;
			}
			else if (pomocnicza == "<mfenced>") {
				fencedopen = 1;
				continue;
			}

			else if (pomocnicza == "</mfenced>" && msupopen == 1) {
				fencedopen = 0;
				continue;
			}
			else if (pomocnicza == "</mfenced>")
				throw 11;


			//mrow

			if (pomocnicza == "<mrow>" && mrowopen == 1) {
				throw 12;
			}
			else if (pomocnicza == "<mrow>") {
				mrowopen = 1;
				continue;
			}

			else if (pomocnicza == "</mrow>" && msupopen == 1) {
				mrowopen = 0;
				continue;
			}
			else if (pomocnicza == "</mrow")
				throw 13;





			else if (pomocnicza[pomocnicza.length() - 1] != '>' || pomocnicza[pomocnicza.length()] - 5 != '<' || pomocnicza[pomocnicza.length() - 4] != '/' || pomocnicza[pomocnicza.length() - 3] != 'm' || pomocnicza[0] != '<' || pomocnicza[1] != 'm' || pomocnicza[3] != '>') {
				if (pomocnicza[2] == 'i' && pomocnicza[pomocnicza.length() - 2] != 'i' || pomocnicza[2] == 'o' && pomocnicza[pomocnicza.length() - 2] != 'o' || pomocnicza[2] == 'n' && pomocnicza[pomocnicza.length() - 2] != 'n')
					throw 3;
				else if (pomocnicza[2] != 'i' && pomocnicza[pomocnicza.length() - 2] == 'i' || pomocnicza[2] != 'o' && pomocnicza[pomocnicza.length() - 2] == 'o' || pomocnicza[2] != 'n' && pomocnicza[pomocnicza.length() - 2] == 'n')
					throw 4;
			}
			else
				throw 2;

			if (pomocnicza[2] == 'i')
			{
				if (!(isalpha(pomocnicza[4])))
					throw 7;
				/*if (isdigit(pomocnicza[4])))
					throw 7;*/
			}
			else if (pomocnicza[2] == 'o')
			{
				if (pomocnicza[4] != '+' && pomocnicza[4] != '=' && pomocnicza[4] != '-' && pomocnicza[4] != '*')
					throw 8;
			}
			else if (pomocnicza[2] == 'n') {
				if (!(isdigit(pomocnicza[4])))
					throw 9;
			}
		}
		catch (int blad) {
			switch (blad) {
			case 1:
				cout <<"Nie zamknieto </math>" << blad << endl;
				return;
			case 2:
				cout << "Taki operator nie istnieje! " << blad << endl;
				return;
			case 3:
				cout << "Zle dokmniety operator! " << blad << endl;
				return;
			case 4:
				cout << "Zle otwarty operator! " << blad << endl;
				return;
			case 5:
				cout << "Niepoprawnie otwarto <msup> " << blad << endl;
				return;
			case 6:
				cout << "Niepoprawnie zamknieto<msup> " << blad << endl;
				return;
			case 7:
				cout << "To nie jest litera " << blad << endl;
				return;
			case 8:
				cout << "To nie jest operatorem " << blad << endl;
				return;
			case 9:
				cout << "To nie jest liczba " << blad << endl;
				return;
			case 10:
				cout << "Niepoprawnie otwarto <mfence>" << blad << endl;
				return;
			case 11:
				cout << "Niepoprawnie zamknieto <mfence> " << blad << endl;
				return;
			case 12:
				cout << "Niepoprawnie otwarto <mrow> " << blad << endl;
				return;
			case 13:
				cout << "Niepoprawnie zamknieto <mrow>" << blad << endl;
				return;
			case 15:
				cout << "Nie domknieto tagu " << blad << endl;
				return;

			}

		}
	}
}

int main() {
	fstream plik;
	plik.open("poprawna.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;
	plik.open("b³¹d nieoczekiwanej wartosci.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;
	plik.open("b³¹d nieoczekiwanej wartosci2.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;
	plik.open("b³¹d operatora.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;
	plik.open("b³¹d tagów.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;
	plik.open("b³¹d tagów2.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;
	plik.open("niedomkniêcie tagow podstawa.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;
	plik.open("niesparowanie tagow.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;
	plik.open("niespodziewana wartosc.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;
	plik.open("niespodziewana wartosc2.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;
	plik.open("niespodziewana wartosc3.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;
	plik.open("niespodziewana wartosc4.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;
	plik.open("poprawna podstawa.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;


	//poziom 2
	cout << "Poziom 2" << endl;
	plik.open("poprawne_rozszerzenie.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;
	plik.open("poprawne_rozszerzenie2.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;
	plik.open("tagi_rozszerzenie.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;
	plik.open("tagi2_rozszerzenie.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;
	plik.open("wartosci_rozszerzenie.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;
	plik.open("wartosci2_rozszerzenie.txt", ios::in);
	funkcja(plik);
	plik.close();
	cout << "FUnkcja wykonana" << endl;
	system("PAUSE");
	return 0;
}