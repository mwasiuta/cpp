#include <iostream>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <math.h>
#include <vector>
#include <set>
#include <time.h>

using namespace std;

double generuj(){
	double i = rand() % 300 - 200;
	return i;
}

void myfunction(double i) {  // function:
	cout << ' ' << i;
}

int sumowanie(int i) {  // function:
	static int wynik = 0;
	wynik += i;
	return wynik;
}

//

class Sum
{
	double t;
public:

	Sum(double i) :t(i){}

	void operator()(double a)
	{
		t += a;
	}
	double result() const
	{
		return t;
	}

};


class Sr
{
	double sr;
public:

	Sr(double i) :sr(i){}

	double operator()(double a)
	{
		return (a-sr);
	}
	double result() const
	{
		return sr;
	}

};

double kwadrat(double i){
	double dokwadratu = i*i;
	return dokwadratu;
}

int main()
{
	srand(time(NULL));
	int n = 10;
	vector<double> liczby(n);
	vector<double> pomocniczy(n);
	double srednia;
	double koncowy;
	Sum sum(0);
	
	
	liczby[0] = -50;
	liczby[1] = 0;
	liczby[2] = 20;
	liczby[3] = 30;
	liczby[4] = 11;
	liczby[5] = 44;
	liczby[6] = 55;
	liczby[7] = 77;
	liczby[8] = 10;
	liczby[9] = 10;
	
	//generate(liczby.begin(), liczby.end(), generuj);

	Sum summa=for_each(liczby.begin(), liczby.end(), sum);
	for_each(liczby.begin(), liczby.end(), myfunction);

	cout << "\nSuma:" << summa.result();
	srednia = (double)summa.result() / n;
	cout << "\nSrednia:" << srednia << endl;
	Sr sr(srednia);
	transform(liczby.begin(), liczby.end(), pomocniczy.begin(), sr);
	cout <<"\nSrednia"<< endl;
	for_each(pomocniczy.begin(), pomocniczy.end(), myfunction);
	transform(pomocniczy.begin(), pomocniczy.end(), pomocniczy.begin(), kwadrat);
	cout << "\nDo kwadratu:"<< endl;
	for_each(pomocniczy.begin(), pomocniczy.end(), myfunction);
	summa = for_each(pomocniczy.begin(), pomocniczy.end(), sum);
	cout << "\nSuma: " << summa.result() << endl;
	koncowy = summa.result() / (n - 1);
	cout <<"Wariancja"<< koncowy <<endl;
	

	system("PAUSE");
	return 0;
}