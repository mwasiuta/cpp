#include <cstdio>
#include <ctype.h>
#include <string>
#include <math.h>
#include "kontener.h"
#include <time.h>
#include <cstdlib>
#include <iostream>


using namespace std;

double randdouble()
{
	
	return (rand() / (double(RAND_MAX) + 1))*10;
}
template<typename T>
void transform(typename Konten<T>::iterator begin1, typename Konten<T>::iterator end1, typename Konten<T>::iterator begin2)
{
	while (begin1 != end1)
	{
		if (*begin1 > *begin2)
			swap(*begin1, *begin2);
		cout << "Kontener 1: " << begin1++;
		cout << "Kontener 2: " << begin2++ << endl;
	}
}


template<typename T>
void roznica(typename Konten<T>::iterator begin1, typename Konten<T>::iterator end1, typename Konten<T>::iterator begin2)
{
	while (begin1 != end1)
	{
		*begin1 = *begin1 - *begin2;
		cout << "Wynik to:" << endl;
		cout << fabs(begin1++) << endl;
		begin2++;
	}
}

template<typename T>
void objetosc(typename Konten<T>::iterator begin1, typename Konten<T>::iterator end1, double &a)
{
	while (begin1 != end1)
	{
		a = a * (*begin1);
		begin1++;
	}

	cout <<"Wynik: "<< fabs(a) << endl;
}


int main(){
	srand(time(NULL));
	double a=1;

	Konten<double> kontener1; //p
	Konten<double> kontener2; //q
	
	for (int i = 0; i<3; i++)
	{
		double losowanie;
		losowanie = randdouble();
		cout << "Kontener 1 wylosowana:" << losowanie << endl;
		kontener1.push(losowanie);
		losowanie = randdouble();
		cout << "Kontener 2 wylosowana:" << losowanie << endl;
		kontener2.push(losowanie);
	}
	transform<double>(kontener1.begin(), kontener1.end(), kontener2.begin());
	
	cout << endl << "Roznicuj." << endl;
	roznica<double>(kontener1.begin(), kontener1.end(), kontener2.begin());

	objetosc<double>(kontener1.begin(), kontener2.end(), a);

	system("PAUSE");
	return 0;
}