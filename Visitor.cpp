#include "Visitor.h"
#include <iostream>


Visitor::Visitor()
{
	this->money = 0;
	this->pocket = nullptr;
	this->userSearch = nullptr;
	this->userSearchSize = 0;
	this->pocketSize = 0;
	this->reservedPocket = nullptr;
	this->reservedPocketSize = 0;
}

Visitor::Visitor(const Visitor& copy)
{
	this->userSearchSize = copy.userSearchSize;
	this->pocketSize = copy.pocketSize;
	this->money = copy.money;
	this->pocket = copy.pocket;
	this->userSearch = copy.userSearch;
	this->reservedPocket = copy.reservedPocket;
	this->reservedPocketSize = copy.reservedPocketSize;
}

double Visitor::GetBalance()
{
	return money;
}

void Visitor::ShowUserSearch()
{
	for (int i = 0; i < userSearchSize; i++)
	{
		userSearch[i].ConsoleOutput();
	}
	std::cout << std::endl;
}

void Visitor::ShowUserPocket()
{
	std::cout << std::endl;
	for (int i = 0; i < pocketSize; i++)
	{
		pocket[i].ConsoleOutput();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Visitor::ShowUserPocketReserved()
{
	std::cout << std::endl;
	for (int i = 0; i < reservedPocketSize; i++)
	{
		reservedPocket[i].ConsoleOutput();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Visitor::TopUpBalance(double money)
{
	this->money += money;
}

Performance Visitor::FindPerformance(TicketWindow data, std::string name)
{
	Performance result;
	for (int i = 0; i < data.getSizeAll(); i++)
	{
		if (data.FindPerformance(name, i))
		{
			result = data[i].GetPerformance();
			if (userSearchSize == 0)
			{
				this->userSearchSize++;
				this->userSearch = new Performance[userSearchSize];
				this->userSearch[0] = result;
			}
			else
			{
				Performance* copy = new Performance[userSearchSize];
				for (int i = 0; i < userSearchSize; i++)
				{
					copy[i] = userSearch[i];
				}
				this->userSearchSize++;
				this->userSearch = new Performance[userSearchSize];
				for (int i = 0; i < userSearchSize - 1; i++)
				{
					this->userSearch[i] = copy[i];
				}
				this->userSearch[i] = data[i].GetPerformance();
				delete[] copy;
			}
		}
	}
	return result;
}

Tickets Visitor::BuyTicket(TicketWindow data, std::string name, int place, int row)
{

	Tickets result;
	for (int i = 0; i < data.getSizeAll(); i++)
	{
		if (data.FindPerformance(name, i))
		{
			if (money > data.getMoney(name))
			{
				if (pocketSize == 0)
				{
					result = data[i].GetTicket();
					this->pocketSize++;
					this->pocket = new Tickets[1];
					this->pocket[0] = data.BuyTicket(name, place, row);
					pocket[0].ChangePlaceAndRow(place, row);
					this->money -= data.getMoney(name);
				}
				else
				{
					Tickets* copy = new Tickets[pocketSize];
					for (int i = 0; i < pocketSize; i++)
					{
						copy[i] = pocket[i];
					}
					this->pocket = new Tickets[pocketSize+1];
					for (int i = 0; i < pocketSize; i++)
					{
						this->pocket[i] = copy[i];
					}
					pocket[pocketSize] = data.BuyTicket(name, place, row);
					pocket[pocketSize].ChangePlaceAndRow(place, row);
					this->pocketSize++;
					delete[] copy;
					this->money - data.getMoney(name);
				}
			}
			else
			{

				std::cout << " You don't have enough money  :( " << std::endl;
			}
		}
	}
	return result;
}

Tickets Visitor::BuyReservedTicket(TicketWindow data, std::string name, int place, int row)
{
	bool temp = false;
	int tempCounter = 0;
	for (int i = 0; i < reservedPocketSize; i++)
	{
		if (name == reservedPocket[i].getPerformance() || name == reservedPocket[i].getAutor() || name == reservedPocket[i].getDate())
		{
			temp = true;
			tempCounter = i;
		}
	}
	Tickets result = reservedPocket[tempCounter];
	if (temp == true)
	{
		Tickets* temp = pocket;
		int tmp = pocketSize;
		this->pocketSize++;
		this->pocket = new Tickets[pocketSize];
		this->pocket[tmp] = result;
		for (int i = 0; i < pocketSize - 1; i++)
		{
			pocket[i] = temp[i];
		}

		Tickets* tempReserv = reservedPocket;
		this->reservedPocket = new Tickets[reservedPocketSize - 1];
		int j = 0;
		for (int i = 0; i < reservedPocketSize - 1; i++)
		{
			if (i != tempCounter)
			{
				reservedPocket[j] = tempReserv[i];
				j++;
			}
		}
		this->reservedPocketSize--;
		int count = 0;
		for (int i = 0; i < data.getSizeAll(); i++)
		{
			if (data.FindPerformance(name, i))
			{
				int counter = count;
			}
		}
		data.ChangePlaceStatus(count, place, row, "Sold");
	}
	return result;
}

Tickets Visitor::ReservTicket(TicketWindow data, std::string name, int place, int row)
{	
	Tickets result = data.ReservTicket(name, place, row);
	Tickets* temp(reservedPocket);
	this->reservedPocketSize++;
	this->reservedPocket = new Tickets[reservedPocketSize];
	for (int i = 0; i < reservedPocketSize-1; i++)
	{
		this->reservedPocket[i] = temp[i];
	}
	reservedPocket[reservedPocketSize - 1] = result;
	this->reservedPocket[reservedPocketSize - 1].ChangePlaceAndRow(place, row);
	return result;
}

Visitor::~Visitor()
{
	if (pocket == nullptr && reservedPocket == nullptr)
	{
		delete[] pocket;
		delete[] reservedPocket;
	}
}
