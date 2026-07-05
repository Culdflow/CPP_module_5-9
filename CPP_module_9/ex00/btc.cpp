#include "btc.hpp"

void	btc::fillBtcData()
{
	std::ifstream	file("data/data.csv");
	if (!file.is_open())
		throw(std::string) "Couldn't open data.csv";
	std::string line;
	getline(file, line);
	while (getline(file, line))
	{
		putLineData(line);
	}
	file.close();
}

void	btc::putLineData(std::string str)
{
	std::string	key = str.substr(0, str.find(','));
	std::string	value_str = str.substr(str.find(',') + 1, str.length());
	float			value = atof(value_str.c_str());
	this->btcData.insert(std::make_pair(key, value));
}
void	btc::fillFileData(char* filename)
{
	std::ifstream	file(filename);
	if (!file.is_open())
		throw(std::string) "Couldn't open user file";
	std::string line;
	getline(file, line);
	while (getline(file, line))
		putLineFile(line, file);
	file.close();
}

void	checkErrorsDay(int year, int month, int day)
{
	int max_day;
	if (month == 2)
	{
		if (year % 4 == 0)
			max_day = 29;
		else
			max_day = 28;
	}
	else
	{
		if (month % 2 == 0)
			max_day = 30;
		else
			max_day = 31; 
	}
	if (day < 1 || day > max_day)
		throw(std::string) "[Invalid Day]: Must be between 1 and the max number of days of that month of that year";
}

void	checkErrorsDate(std::string str)
{
	std::istringstream sstream(str);
	std::string year;
	std::string	month;
	std::string	day;
	int			int_year;
	int			int_month;
	int			int_day;

	getline(sstream, year, '-');
	getline(sstream, month, '-');
	getline(sstream, day, '-');

	int_year = atoi(year.c_str());
	int_month = atoi(month.c_str());
	int_day = atoi(day.c_str());

	if (int_year < 2009 || int_year > 2022)
		throw(std::string) "[Invalid Year]: Has to be between 2009 - 2025";
	if (int_month < 1 || int_month > 12)
		throw(std::string) "[Invalid Month]: Has to be between 1 - 12";
	checkErrorsDay(int_year, int_month, int_day);
}

void	btc::putLineFile(std::string str, std::ifstream& file)
{
	std::string	key = str.substr(0, str.find('|'));
	std::string	value_str = str.substr(str.find('|') + 1, str.length());
	float			value = atof(value_str.c_str());
	this->btcData.insert(std::make_pair(key, value));
	(void)file;
}

btc::btc()
{
	fillBtcData();
}