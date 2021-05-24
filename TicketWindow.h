#pragma once
#include "TicketWindowStructure.h"

class TicketWindow
{
public:

	TicketWindow();
	TicketWindow(const TicketWindow& copy);
	TicketWindow(std::string fileNamePerformance, std::string fileNameTickets);
	Tickets BuyTicket(std::string value, int place, int row);
	TicketWindowStructure operator[](int index);
	void ChangePlaceStatus(int index, int plcae, int row, std::string value);
	bool FindPerformance(std::string, int i);
	int getSizeAll();
	int getMoney(std::string name);
	int GetSizeHall(std::string value);
	void ConsoleOutput();
	Tickets ReservTicket(std::string value, int place, int row);
	~TicketWindow();

private:
	int _size;
	TicketWindowStructure* _till;
};

