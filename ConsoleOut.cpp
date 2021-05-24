#include "ConsoleOut.h"
#include <iostream>
#include "Performance.h"
#include "Tickets.h"
#include "TicketWindow.h"
#include <iomanip> 
#include "Visitor.h"
#include <fstream>

using namespace std;

void ConsoleOut::Console()
{
	string input;
	TicketWindow mainData;
	while (input != "exit")
	{
		Visitor user;
		cout << "Hello user, do You want to login as administrator ? " << endl;
		cout << "1 - yes " << endl << "2 - no" << endl;
		cin >> input;
		if (input == "1")
		{
			while (input != "back")
			{
				cout << " input password (123 ;) )" << setw(5) << "input ""back"" for exit" << endl;
				cin >> input;
				{
					if (input == "123" && input != "back")
					{
						while (input != "back")
						{
							cout << "Now you are administrator" << endl;
							string temp;
							cout << " input filename for performance " << endl;
							cin >> input;
							while (!(ifstream(input).is_open()))
							{
								cout << "File dosnt exist " << endl;
								cin.clear();
								cin >> input;

							}
							cout << " input filename for tickets " << endl;
							cin >> temp;
							if (temp == "back")
							{
								input = temp;
							}
							while (!(ifstream(temp).is_open()))
							{
								if (temp == "back")
								{
									input = temp;
								}
								cout << "File dosnt exist " << endl;
								cin.clear();
								cin >> temp;

							}
							TicketWindow tampInput(input, temp);
							mainData = tampInput;
							while (input != "back")
							{
								cout << "If you want to see all Performance - 1" << endl;
								cin >> input;
								if (input == "1")
								{
									mainData.ConsoleOutput();
								}
							}
						}
					}
					else
					{
						cout << "Incorrect password" << endl;
					}
				}
			}
		}
		else if (input == "2")
		{
			while (input != "back")
			{
				cout << "Hello, visiter" << endl;
				cout << endl;
				cout << "If you want to replenish the balance - 1" << endl;
				cout << "If you want to see all performance - 2" << endl;
				cout << "If you want to find performance - 3" << endl;
				cout << "If you want to buy ticket - 4" << endl;
				cout << "If you want to reserv ticket - 5" << endl;
				cout << "If you want to see your balance - 6" << endl;
				cout << "If you want to see your search - 7" << endl;
				cout << "If you want to see your tickets - 8" << endl;
				cout << "If you want to buy reserved ticket - 9" << endl;
				cout << "If you want to see your reserved tickets - 10" << endl;
				cout << endl;
				cin >> input;
				if (input == "1")
				{
					cout << " How much ? " << endl;
					double money;
					cin >> money;
					if (money <= 0 || money >= 0)
					{
						user.TopUpBalance(money);
					}
					else
					{
						cout << "Incorrect input" << endl;
					}
				}
				else if (input == "2")
				{
					mainData.ConsoleOutput();
				}
				else if (input == "3")
				{
					cout << "Please input name, date, autor or genre" << endl;
					cin >> input;
					user.FindPerformance(mainData, input).ConsoleOutput();
				}
				else if (input == "4")
				{
					cout << "Please input name, date, autor or genre" << endl;
					cin >> input;
					cout << "Please input place " << endl;
					int place = 0;
					while (!(cin >> place))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Input a number" << endl;
					}
					if (place < 0 || place > mainData.GetSizeHall(input))
					{
						cout << "Out of hall range" << endl;
						break;
					}
					cout << "Please input row" << endl;
					int row = 0;
					while (!(cin >> row))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Input a number" << endl;
					}
					if (row < 0 || row > mainData.GetSizeHall(input))
					{
						cout << "Out of hall range" << endl;
						break;
					}
					user.BuyTicket(mainData, input, place, row);
				}
				else if (input == "5")
				{
					cin.clear();
					cout << "Please input name, date, autor or genre" << endl;
					cin >> input;
					cout << "Please input place " << endl;
					int place = 0;
					while (!(cin >> place))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Input a number" << endl;
					}
					if (place < 0 || place > mainData.GetSizeHall(input))
					{
						cout << "Out of hall range" << endl;
						break;
					}
					cout << "Please input row" << endl;
					int row = 0;
					while (!(cin >> row))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Input a number" << endl;
					}
					if (row < 0 || row > mainData.GetSizeHall(input))
					{
						cout << "Out of hall range" << endl;
						break;
					}
					user.ReservTicket(mainData, input, place, row);
				}
				else if (input == "6")
				{
					cout << user.GetBalance() << endl;
				}
				else if (input == "7")
				{
					user.ShowUserSearch();
				}
				else if (input == "8")
				{
					user.ShowUserPocket();
				}
				else if (input == "9")
				{
					cout << "Please input name, date, autor or genre" << endl;
					cin >> input;
					cout << "Please input place " << endl;
					int place;
					while (!(cin >> place))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Input a number" << endl;
					}
					cout << "Please input row" << endl;
					int row;
					while (!(cin >> row))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Input a number" << endl;
					}
					user.BuyReservedTicket(mainData, input, place, row);
				}
				else if (input == "10")
				{
				user.ShowUserPocketReserved();
				}
				else
				{
					cout << " Incorrect input " << endl;
				}
			}
		}
		else
			if (input != "exit")
			{
				cout << " Incorrect input " << endl;
			}
	}
}

ConsoleOut::ConsoleOut()
{
}
