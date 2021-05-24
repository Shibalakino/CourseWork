#include "Performance.h"
#include "nlohmann/json.hpp"
#include <string>
#include <fstream>
#include <iostream>

using json = nlohmann::json;


Performance::Performance(std::string input_autor, std::string input_name, std::string input_genre, std::string input_date)
{
	this->name = input_name;
	this->autor = input_autor;
	this->genre = input_genre;
	this->date = input_date;
}

Performance::Performance()
{
	this->name = "";
	this->autor = "";
	this->genre = "";
	this->date = "";
}

Performance::Performance(const Performance& copy)
{
	this->autor = copy.autor;
	this->name = copy.name;
	this->genre = copy.genre;
	this->date = copy.date;
}

bool Performance::CheckPerformance(std::string value)
{
	bool result = false;
	if (value == autor || value == name || value == genre || value == date)
	{
		result = true;
	}
	return result;
}

void Performance::ConsoleOutput()
{
	std::cout << "Autor - " << autor << std::endl;
	std::cout << "Name - " << name << std::endl;
	std::cout << "Genre - " << genre << std::endl;
	std::cout << "Data - " << date << std::endl;
	std::cout << std::endl;
}

