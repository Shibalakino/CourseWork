#pragma once
#include "Performance.h"
#include <string>

class Tickets : private Performance
{

public:

	Tickets();
	Tickets(const Tickets& copy, const Performance& daddy);
	Tickets(const Tickets& copy);
	Tickets(std::string time, double price, int hallSize, Performance& daddy);
	int getMoney();
	int GetHallSize();
	std::string getPerformance();
	std::string getAutor();
	std::string getDate();
	void ChangePlaceAndRow(int place, int row);
	void ConsoleOutput();


private:

	int _place;
	int _row;
	int _hallSize;
	double _price;
	std::string _time;
};

