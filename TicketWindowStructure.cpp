#include "TicketWindowStructure.h"
#include "Performance.h"
#include "Tickets.h"
#include <iostream>
#include <iomanip>

TicketWindowStructure::TicketWindowStructure(Performance per, Tickets tick)
{
	Performance temp0(per);
	this->_p = temp0;
	Tickets temp1(tick, _p);
	this->_t = temp1;
	int hallSize = tick.GetHallSize();
	this->_ticketSize = hallSize* hallSize;
	this->_hallSize = hallSize;
	_hall = new std::string * [_hallSize];
	for (int i = 0; i < _hallSize; i++)
	{
		_hall[i] = new std::string[_hallSize];
		for (int j = 0; j < _hallSize; j++)
		{
			this->_hall[i][j] = "Avaible";
		}
	}
}

bool TicketWindowStructure::CheckHallPlaceStatus(std::string status, int place, int row)
{
	if (this->_hall[place][row] == status)
	{
		return true;
	}
	return false;
}

Tickets TicketWindowStructure::GetTicket()
{
	Tickets temp(this->_t);
	return temp;
}

int TicketWindowStructure::GetTicketSize()
{
	return this->_ticketSize;
}

Performance TicketWindowStructure::GetPerformance()
{
	Performance temp(this->_p);
	return temp;
}

void TicketWindowStructure::ChangeTicketSize(int num)
{
	this->_ticketSize = num;
}

TicketWindowStructure::TicketWindowStructure()
{
	this->_hallSize = 0;
	this->_ticketSize = 0;
	this->_hall = nullptr;
}

void TicketWindowStructure::operator=(TicketWindowStructure right)
{
	this->_p = right._p;
	this->_t = right._t;
	this->_ticketSize = right._ticketSize;
	this->_hallSize = right._hallSize;
	this->_hall = right._hall;
}

TicketWindowStructure::TicketWindowStructure(int size)
{
	this->_ticketSize = size;
	_hall = new std::string * [_ticketSize];
	for (int i = 0; i < _ticketSize; i++)
	{
		_hall[i] = new std::string[_ticketSize];
		for (int j = 0; j < _ticketSize; j++)
		{
			_hall[i][j] = " ";
		}
	}
}

TicketWindowStructure::TicketWindowStructure(const TicketWindowStructure& copy)
{
	this->_p = copy._p;
	this->_t = copy._t;
	this->_ticketSize = copy._ticketSize;
	this->_hallSize = copy._hallSize;
	this->_hall = copy._hall;
}



void TicketWindowStructure::ConsoleOutput()
{
	_t.ConsoleOutput();
	std::cout << "Hall : " << std::endl;
	std::cout << "            ";
	for (int i = 0; i < _hallSize; i++)
	{
		std::cout << i;
		std::cout << std::setw(13+1);
	}
	std::cout << std::endl;
	for (int i = 0; i < _hallSize; i++)
	{ 
		std::cout << std::setw(0);
		std::cout << i;
		std::cout << "     ";
		for (int j = 0; j < _hallSize; j++)
		{
		    std::cout << std::setw(10);
			std::cout  << _hall[i][j] << "    ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void TicketWindowStructure::ChangePlaceStatus(int place, int row, std::string value)
{
	this->_hall[place][row] = value;
}


TicketWindowStructure::~TicketWindowStructure()
{
	if (_hall == nullptr)
	{
		for (int i = 0; i < _hallSize; i++)
		{
			delete[] _hall[i];
		}
		delete[] _hall;
	}
}

int TicketWindowStructure::GetHallSize()
{
	return _hallSize;
}
