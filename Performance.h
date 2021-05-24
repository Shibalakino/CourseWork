#pragma once
#include <string>

class Performance
{

public:
	Performance(std::string autor, std::string name, std::string genre, std::string date);
	Performance();
	Performance(const Performance& copy);
	bool CheckPerformance(std::string value);
	void ConsoleOutput();

protected:
	std::string autor;
	std::string name;
	std::string genre;
	std::string date;
};

