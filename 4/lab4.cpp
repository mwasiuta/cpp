#include <cstdio>
#include <iostream>
#include <math.h>
#include <string>
#include <ctype.h>
#include <queue>
#include <list>
#include <fstream>
#include <sstream>
#include <istream>

using namespace std;

/*
template <class T>
struct greater : binary_function <T, T, bool> {
	bool operator() (const T& x, const T& y) const {
		return x > y;
	}
};


template <>
struct greater <string> {
	bool operator() (const string& x, const string& y) {
		return x.length() > y.length();
	}
};
*/
template <class T>
struct greater {
	bool operator() (const T& x, const T& y) const {
		return x > y;
	};
	typedef T first_argument_type;
	typedef T second_argument_type;
	typedef bool result_type;
};

template <>
struct greater <string> {
	bool operator() (const string& x, const string& y) const {
		return x.length() > y.length();
	};
};



using String_Queue = priority_queue<string, vector<string>, greater<string>>;








template <class T>
struct notgreater {
	bool operator() (const T& x, const T& y) const {
		return x < y;
	};
	typedef T first_argument_type;
	typedef T second_argument_type;
	typedef bool result_type;
};

template <>
struct notgreater <String_Queue> {
	bool operator() (const	String_Queue& x, const String_Queue& y) const {
		return x.size() < y.size();
	};
};

/*
template <class T>
struct smaller : binary_function <T, T, bool> {
	bool operator() (const T& x, const T& y) const {
		return x < y;
	}
};


template <>
struct smaller <String_Queue> {
	bool operator() (const String_Queue& x, const String_Queue& y) const {
		return x.size() < y.size();
	}
};
*/

ostream &operator<<(ostream &os, String_Queue &rv){
	os << rv.size() << " :";
	while(!rv.empty()){
		os << rv.top();
		rv.pop();
	}
	os << endl;
	return os;
}

class Mikser:public list<String_Queue>{
public:

	Mikser(){

	}
	Mikser(string nazwa){
		this->Open(nazwa);
	}
	~Mikser(){
		for (iterator i = this->begin(); i != this->end(); ++i)
		{
			while (!i->empty()){
				i->pop();
			}
			
		}
		while (!this->empty()){
			this->pop_front();
		}
		
	}
	void Open(string nazwa){
		fstream plik;
		plik.open(nazwa, ios::in);
		string slowo=" ", wiersz;
		
		while (getline(plik, wiersz)){
			if (wiersz == "") continue;
			String_Queue pomocnicza;
			string wczesniejsza;
			istringstream stream(wiersz);
			do{
				wczesniejsza = slowo;
				stream >> slowo;
				if (wczesniejsza == slowo){
					continue;
				}
				pomocnicza.push(slowo);
			} while (stream);
			this->push_back(pomocnicza);
		}

		plik.close();

	}
	void Execute(){
		this->sort(notgreater<String_Queue>());
	}

	void Write(string nazwa){
		fstream plik;
		plik.open(nazwa, ios::out);
		for (iterator i = this->begin(); i != this->end(); ++i)
		{
			plik << *i;
		}
	}

};

int main()
{
	Mikser nowy;
	nowy.Open("mistrz.txt");
	nowy.Execute();
	nowy.Write("swoj.txt");
	system("PAUSE");
	return 0;
}