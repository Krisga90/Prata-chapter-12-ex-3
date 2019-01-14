

#pragma once
#ifndef STOCK2O_H_
#define STOCK2O_H_
#include <iostream>

class Stocks
{
private:
	char * company;
	long shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }

public:
	Stocks();
	Stocks(const char * co, long n = 0, double pr = 0);
	~Stocks();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show() const;
	const Stocks & topval(const Stocks & s)const;
	friend std::ostream & operator<<(std::ostream & os, const Stocks & s);

};

#endif

