#include <iostream>
#include "stock20.h"



Stocks::Stocks()
{
	size_t l_t = strlen("Bez nazwy");
	company = new char[l_t + 1];
	strcpy_s(company, l_t+1, "Bez nazwy");
	company[l_t] = '\0';
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
Stocks::Stocks(const char * co, long n, double pr)
{
	size_t l_t = strlen(co);
	company = new char[l_t + 1];
	strcpy_s(company, l_t+1, co);  //musi byc wielkosc bufora (ca³a)
	company[l_t] = '\0';
	if (n < 0)
	{
		std::cout << "Liczba udzialow nie moze byc ujemna; "
			"ustalam liczbe udzialow w " << company << " na 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}
Stocks::~Stocks()
{
	delete[] company;
}

void Stocks::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Liczba nabywanych udzialow nie moze byc ujemna. "
			"Transakcja przerwana.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stocks::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		cout << "Liczba sprzedawanych udzialow nie moze byc ujemna. "
			"Transakcja przerwana.\n";
	}
	else if (num > shares)
	{
		cout << "Nie mozesz sprzedac wiecej udzialow niz posiadasz! "
			"Transakcja przerwana.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stocks::update(double price)
{
	share_val = price;
	set_tot();

}

void Stocks::show()const
{
	using std::cout;
	using std::ios_base;
	//ustawienie formatu na #.###
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);

	cout << "Spolka: " << company << "\nLiczba udialow: " << shares <<
		"\nCena udzialow: " << share_val << " zl.";

	// ustawienie formatu na #.##
	cout.precision(2);
	cout << "\nLaczna wartosc udzialow: " << total_val << "zl.\n";
	//przywrócenie pierwotnego formatowania
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);

}

const Stocks & Stocks::topval(const Stocks & s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}


std::ostream & operator<<(std::ostream & os, const Stocks & s)
{
	using std::ios_base;
	//ustawienie formatu na #.###
	ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = os.precision(3);

	os << "Spolka: " << s.company << "\nLiczba udialow: " << s.shares <<
		"\nCena udzialow: " << s.share_val << " zl.";

	// ustawienie formatu na #.##
	os.precision(2);
	os << "\nLaczna wartosc udzialow: " << s.total_val << "zl.\n";
	//przywrócenie pierwotnego formatowania
	os.setf(orig, ios_base::floatfield);
	os.precision(prec);

	return os;
}