#include "btc.hpp"

btc::btc()
{
	fillBtcData();
}

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
		throw(btc::DateDayNotValid());
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

	if (int_year < 1990 || int_year > 2022)
		throw(btc::DateYearNotValid());
	if (int_month < 1 || int_month > 12)
		throw(btc::DateMonthNotValid());
	checkErrorsDay(int_year, int_month, int_day);
}

int*	cmpDateHelper(std::string date)
{
	int	*result = new int [3];
	std::istringstream sstream(date);
	std::string year;
	std::string	month;
	std::string	day;

	getline(sstream, year, '-');
	getline(sstream, month, '-');
	getline(sstream, day, '-');
	result[0] = atoi(year.c_str());
	result[1] = atoi(month.c_str());
	result[2] = atoi(day.c_str());
	return (result);
}

bool	btc::cmpDate(std::string date1, std::string date2)const
{
	int*	date1INT = cmpDateHelper(date1);
	int*	date2INT = cmpDateHelper(date2);
	bool	rtrn = true;

	if (date1INT[0] != date2INT[0])
		rtrn = date1INT[0] < date2INT[0];
	else if (date1INT[1] != date2INT[1])
		rtrn = date1INT[1] < date2INT[1];
	else if (date1INT[2] != date2INT[2])
		rtrn = date1INT[2] < date2INT[2];
	delete [] date1INT;
	delete [] date2INT;
	return (rtrn);
}

void	btc::putLineFile(std::string str, std::ifstream& file)
{
	std::string	key = str.substr(0, str.find('|'));
	std::string	value_str = str.substr(str.find('|') + 1, str.length());
	float			value = atof(value_str.c_str());
	// std::cout << key << std::endl;
	// std::cout << value << std::endl;
	try
	{
		checkErrorsDate(key);
	}
	catch (btc::DateDayNotValid& e)
	{
		std::cout << e.what() << std::endl;
		file.close();
	}
	catch (btc::DateMonthNotValid& e)
	{
		std::cout << e.what() << std::endl;
		file.close();
	}
	catch (btc::DateYearNotValid& e)
	{
		std::cout << e.what() << std::endl;
		file.close();
	}
	(void)file;
	this->filedata.insert(std::make_pair(key, value));
}

btc::~btc()
{}

const char*	btc::DateYearNotValid::what(void) const throw()
{
	return ("[Invalid Year]: Has to be between 2009 - 2025");
}

const char* btc::DateMonthNotValid::what(void) const throw()
{
	return ("[Invalid Month]: Has to be between 1 - 12");
}

const char* btc::DateDayNotValid::what(void) const throw()
{
	return ("[Invalid Day]: Must be between 1 and the max number of days of that month of that year");
}

void 	btc::print_btc()
{
	std::map<std::string, float>::const_iterator it_data;
	std::map<std::string, float>::const_iterator it_file;
	for(it_file = this->filedata.begin(); it_file != this->filedata.end(); it_file++)
	{
		int i = 0;
		for (it_data = this->btcData.begin(); this->cmpDate(it_data->first, it_file->first); it_data++)
		{
			i++;
		}
		if (i > 0)
			it_data--;
		std::cout << it_file->first << " => " << it_data->second << " = " << it_file->second * it_data->second << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, const btc& BTC)
{
	std::map<std::string, float>::const_iterator it_data;
	std::map<std::string, float>::const_iterator it_file;
	for(it_file = BTC.filedata.begin(); it_file != BTC.filedata.end(); it_file++)
	{
		int i = 0;
		for (it_data = BTC.btcData.begin(); BTC.cmpDate(it_data->first, it_file->first); it_data++)
		{
			i++;
		}
		if (i > 0)
			it_data--;
		std::cout << it_file->first << " => " << it_data->second << " = " << it_file->second * it_data->second << std::endl;
	}
	return (os);
}
