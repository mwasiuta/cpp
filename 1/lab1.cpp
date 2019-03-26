#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include"Tablica.h"
using namespace std;

const int rozmiar=6;
struct Dane {
	int id;
	char nazwa[10];
	double temp;
	double pojemn;

	Dane& operator+=(const Dane& nowy) {
		temp += nowy.temp;
		pojemn += nowy.pojemn;
		return *this;
	};

};

class FIFO {
private:
	Tablica <Dane, rozmiar> nowa;
	FIFO *wsk;
	
public:
	void put(Tablica <Dane, rozmiar> nowe) {
		
	}
	FIFO *get() {

		return wsk;
	}


	FIFO() {
		return;
	}
	
};

ostream& operator << (ostream & b, const Dane & p)
{
	b << '|';
	b.width(6);
	b.fill('0');
	b.setf(ios::right);
	b << p.id;
	b.unsetf(ios::right);

	b << '|';
	b.width(10);
	b.fill(' ');
	b.setf(ios::left);
	b << p.nazwa;
	b << '|';
	b.unsetf(ios::left);

	b.setf(ios::right);
	b.width(7);
	b.precision(1);
	b.setf(ios::fixed);
	b << p.temp;
	b << '|';

	b.width(6);
	b.precision(0);
	b << p.pojemn;
	b << '|';

	return b << endl;
}


void raport(Tablica<Dane, rozmiar> &tab, string nazwa, ios_base::fmtflags ioflag);

int main()
{
	FIFO *kolejka= new FIFO();
	FIFO *zabrany;
	FIFO *wkladany;
	string nazwa;
	cout << "Podaj nazwe do zapisu" << endl;
	cin >> nazwa;
	
	


	Tablica<Dane, rozmiar> dane;
	for (int i = 0; i < rozmiar; i++)
	{
		dane[i].id = i+1;
		strcpy(dane[i].nazwa, "blab1la");
		dane[i].pojemn = i;
		dane[i].temp = i * 10;
	}

	zabrany = kolejka->get();
	kolejka = kolejka->get();

	wkladany->put(dane);

	raport(dane, nazwa, ios::out);

	return 0;
}

void raport(Tablica<Dane, rozmiar> &tab, string nazwa, ios_base::fmtflags flaga)
{
	if (flaga != ios::out)
		return;
	fstream stream;
	stream.open(nazwa, flaga);
	time_t t;
	struct tm *tt;
	time(&t);
	tt = localtime(&t);
	stream.width(40);
	stream << asctime(tt) << endl;
	stream << getenv("COMPUTERNAME");
	stream << "\n+------+----------+-------+------+" << endl;
	stream << "| ID | nazwa | temp. |pojemn|" << endl;
	stream << "+------+----------+-------+------+" << endl;
	Dane ost;
	ost.pojemn = 0;
	ost.temp = 0;
	strcpy(ost.nazwa, " ");
	ost.id = 0;
	for (int i = 0; i < rozmiar; i++)
	{
		stream << tab[i];
		ost += tab[i];
	}
	stream << "+------+----------+-------+------+" << endl;
	stream << ost;
	stream << "+------+----------+-------+------+" << endl;
	stream.close();
}