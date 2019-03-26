template<typename T>
class Lista
{
public:
	T wartosc;
	Lista<T> *nast;

	Lista(T wartosc) : wartosc(wartosc), nast(NULL) {}
	~Lista() { delete nast; }
};

template<typename T>
class Konten
{
	Lista<T> *glowa;
	Lista<T> *nast;
	int top;
public:
	Konten() : top(), glowa(NULL), nast(NULL) {}
	~Konten() { delete nast; }

	void push(T i)
	{
		if (glowa == NULL)
		{
			glowa = new Lista<T>(i);
			nast = glowa;
		}
		else
		{
			nast->nast = new Lista<T>(i);
			nast = nast->nast;
		}
		top++;
	};
	T pop()
	{
		top--;
		Lista<T> *temp = nast;
		nast = glowa;

		while (nast->nast != NULL)
		{
			if (nast->nast->nast == NULL)
			{
				nast = nast->nast;
				nast->nast = NULL;
				break;
			}
			nast = nast->nast;
		}
		return temp;
	};
	int rozmiar() { return top; };

	class iterator
	{
		Konten& s;
		int index;
		Lista <T> *temp;
		T a;
	public:
		iterator(Konten& is) : s(is), index(0), temp(s.glowa) {};
		iterator(Konten& is, bool) : s(is), index(s.top) {};
		T operator++() // Prefix
		{
			a = temp->wartosc;
			temp++;
			return a;
		};
		T operator++(int) // Postfix
		{
			a = temp->wartosc;
			temp++;
			return a;
		};
		T& operator*() const
		{

			Lista<T> *temp2 = s.glowa;
			for (int i = 0; i < index; i++)
				temp2 = temp2->nast;
			return temp2->wartosc;
		};
		iterator& operator=(const iterator& rv)
		{
			s = rv.s;
			index = rv.index;
			return *this;
		}
		bool operator==(const iterator& rv) const
		{
			return index == rv.index;
		}
		bool operator!=(const iterator& rv) const
		{
			return index != rv.index;
		}
		void ResetToEnd() { index = s.top; }
		void ResetToBegin() { index = 0; }
	};
	iterator begin() { return iterator(*this); };
	iterator end() { return iterator(*this, true); };

	friend class iterator;
};