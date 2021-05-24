#include "Tickets.h"
#include "Performance.h"
#include <iostream>

Tickets::Tickets()
{
	this->autor = " ";
	this->name = " ";
	this->genre = " ";
	this->date = " ";
	this->_time = " ";
	this->_place = 0;
	this->_row = 0;
	this->_price = 0;
	this->_hallSize = 0;
}
Tickets::Tickets(const Tickets& copy)
{
	this->autor = copy.autor;
	this->name = copy.name;
	this->genre = copy.genre;
	this->date = copy.date;
	this->_place = copy._place;
	this->_row = copy._row;
	this->_price = copy._price;
	this->_time = copy._time;
	this->_hallSize = copy._hallSize;
}

void Tickets::ChangePlaceAndRow(int place, int row)
{
	this->_place = place;
	this->_row = row;
}

Tickets::Tickets(const Tickets& copy, const Performance& daddy) : Performance(daddy)
{
	this->autor = autor;
	this->name = name;
	this->genre = genre;
	this->date = date;
	this->_time = copy._time;
	this->_place = copy._place;
	this->_row = copy._row;
	this->_price = copy._price;
	this->_hallSize = copy._hallSize;
}

std::string Tickets::getPerformance()
{
	return this->name;
}

std::string Tickets::getAutor()
{
	return this->autor;
}

std::string Tickets::getDate()
{
	return this->date;
}

int Tickets::getMoney()
{
	return _price;
}

int Tickets::GetHallSize()
{
	return this->_hallSize;
}


Tickets::Tickets(std::string time, double price, int hallSize, Performance& daddy) : Performance(daddy)
{
	this->autor = autor;
	this->name = name;
	this->genre = genre;
	this->date = date;
	this->_place = 0;
	this->_row = 0;
	this->_price = price;
	this->_time = time;
	this->_hallSize = hallSize;
}

void Tickets::ConsoleOutput()
{
	std::cout << "Autor - " << autor << std::endl;
	std::cout << "Name - " << name << std::endl;
	std::cout << "Genre - " << genre << std::endl;
	std::cout << "Date - " << date << std::endl;
	std::cout << "Place - " << _place << std::endl;
	std::cout << "Row - " << _row << std::endl;
	std::cout << "Price - " << _price << std::endl;
	std::cout << "Time - " << _time << std::endl;
	std::cout << "Hall Size - " << _hallSize*_hallSize << std::endl;
}
