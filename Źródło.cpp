#include <iostream>
#include "stock20.h"

const int STKS = 4;

int main()
{
	Stocks stock[STKS] =
	{
		Stocks("NanoSmart",10,20.0),
		Stocks("BurakPOL",200,2.0),
		Stocks("GruzPOL",130,6.5),
		Stocks("FutroPOL",60,6.5)
	};
	std::cout << "Portfel inwestycyjny:\n";
	int st;
	for (st = 0; st < STKS; st++)
	{
		std::cout << stock[st] << std::endl;
	}
	const Stocks * top = &stock[0];
	for (st = 1; st < STKS; st++)
	{
		top = &top->topval(stock[st]);
	}
	std::cout << "\nNAjbardziej wartoœciowy pakiet:\n"<<*top<<std::endl;

	std::cin.get();
	return 0;
}