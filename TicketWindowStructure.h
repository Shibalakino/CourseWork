#pragma once
#include "Performance.h"
#include "Tickets.h"

class TicketWindowStructure
{

public:
	
	TicketWindowStructure();
	TicketWindowStructure(int size);
	TicketWindowStructure(const TicketWindowStructure& copy);
	TicketWindowStructure(Performance per, Tickets tick);
	bool CheckHallPlaceStatus(std::string status, int place, int row);
	int GetHallSize();
	int GetTicketSize();
	void ChangeTicketSize(int num);
	void operator=(TicketWindowStructure right);
	void ConsoleOutput();
	void ChangePlaceStatus(int place, int row, std::string value);
	Tickets GetTicket();
	Performance GetPerformance();
	~TicketWindowStructure();
	
private:
	std::string** _hall;
	int _ticketSize;
	int _hallSize;
	Performance _p;
	Tickets _t;
};

