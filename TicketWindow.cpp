#include "TicketWindow.h"
#include "nlohmann/json.hpp"
#include <string>
#include <fstream>
#include "Performance.h"
#include "Tickets.h"
#include "TicketWindowStructure.h"
#include <iostream>

using json = nlohmann::json;


TicketWindow::TicketWindow()
{
	this->_size = 0;
	this->_till = nullptr;
}

TicketWindow::TicketWindow(const TicketWindow& copy)
{
	this->_size = copy._size;
	this->_till = copy._till;
}


TicketWindow::TicketWindow(std::string fileNamePerformance, std::string fileNameTickets)
{
	std::ifstream i(fileNamePerformance);
	json j;
	i >> j;
	std::ifstream n(fileNameTickets);
	json k;
	n >> k;
	this->_size = j["Poster"].size();
	_till = new TicketWindowStructure[_size];
	for (int i = 0; i < _size; i++)
	{
		Performance temp0((j["Poster"][i]["autor"]).get<std::string>(),
			j["Poster"][i]["name"].get<std::string>(),
			j["Poster"][i]["genre"].get<std::string>(),
			j["Poster"][i]["date"].get<std::string>());
		Tickets temp1((k["Ticket"][i]["time"]).get<std::string>(),
			k["Ticket"][i]["price"].get<int>(),
			k["Ticket"][i]["hallSize"].get<int>(), temp0);
		TicketWindowStructure _till(temp0, temp1);
		this->_till[i] = _till;
	}
}


bool TicketWindow::FindPerformance(std::string value, int i)
{
	bool result = false;
	if (value == _till[i].GetTicket().getPerformance() || value == _till[i].GetTicket().getAutor() || value == _till[i].GetTicket().getDate())
	{
		result = true;
	}
	return result;
}


int TicketWindow::getSizeAll()
{
	return _size;
}

int TicketWindow::getMoney(std::string name)
{
	for (int i = 0; i < _size; i++)
	{
		if (FindPerformance(name, i))
		{
			return _till[i].GetTicket().getMoney();
		}
	}
	return 0;
}

int TicketWindow::GetSizeHall(std::string value)
{
	int resultPosition = 0;
	int counter = 0;
	for (int i = 0; i < _size; i++)
	{
		if (FindPerformance(value, i))
		{
			counter++;
			resultPosition = i;
		}
	}
	if (counter > 1)
	{
		std::cout << "Input more details about performance " << std::endl;
		std::string temp;
		std::cin >> temp;
		GetSizeHall(value);
	}
	else
	{
		int result = _till[resultPosition].GetHallSize();
		return result;
	}
}


Tickets TicketWindow::BuyTicket(std::string value, int place, int row)
{
	int resultPosition = 0;
	int counter = 0;
	for (int i = 0; i < _size; i++)
	{
		if (FindPerformance(value, i))
		{
			counter++;
		}
	}
	if (counter > 1)
	{
		std::cout << "Input more details" << std::endl;
		std::string temp;
		std::cin >> temp;
		BuyTicket(temp, place, row);
	}
	else
	{
		for (int i = 0; i < _size; i++)
		{
			if (FindPerformance(value, i))
			{
				if (_till[i].GetTicketSize() <= 0)
				{
					std::cout << " Sorry, but all tickets have been sold " << std::endl;
				}
				else
				{
					if (_till[i].CheckHallPlaceStatus("Sold", place, row) || _till[i].CheckHallPlaceStatus("Reserved", place, row))
					{
						std::cout << "This place already busy" << std::endl;
					}
					else
					{
						_till[i].ChangeTicketSize(_till[i].GetTicketSize() - 1); // -= 1;
						ChangePlaceStatus(i, place, row, "Sold");
						resultPosition = i;
					}
				}
			}
		}
	}
	return _till[resultPosition].GetTicket();
}

Tickets TicketWindow::ReservTicket(std::string value, int place, int row)
{
	int resultPosition = 0;
	int counter = 0;
	for (int i = 0; i < _size; i++)
	{
		if (FindPerformance(value, i))
		{
			counter++;
		}
	}
	if (counter > 1)
	{
		std::cout << "Input more details" << std::endl;
		std::string temp;
		std::cin >> temp;
		ReservTicket(temp, place, row);
	}
	else
	{
		for (int i = 0; i < _size; i++)
		{
			if (FindPerformance(value, i))
			{
				if (_till[i].GetTicketSize() <= 0)
				{
					std::cout << " Sorry, but all tickets have been sold " << std::endl;
				}
				else
				{
					if (_till[i].CheckHallPlaceStatus("Sold", place, row)  || _till[i].CheckHallPlaceStatus("Reserved", place, row))
					{
						std::cout << "This place already busy" << std::endl;
					}
					else
					{
						_till[i].ChangeTicketSize(_till[i].GetTicketSize() - 1); //=-1
						ChangePlaceStatus(i, place, row, "Reserved");
						resultPosition = i;
					}
				}
			}
		}
	}
	return _till[resultPosition].GetTicket();
}

TicketWindowStructure TicketWindow::operator[](int index)
{
	return _till[index];
}


void TicketWindow::ChangePlaceStatus(int index, int place, int row, std::string value)
{
	this->_till[index].ChangePlaceStatus(place, row, value);
}


void TicketWindow::ConsoleOutput()
{
	for (int i = 0; i < _size; i++)
	{
		_till[i].ConsoleOutput();
	}
	std::cout << std::endl;
}

TicketWindow::~TicketWindow()
{
	if (_till == nullptr)
	{
		delete[] _till;
	}
}
