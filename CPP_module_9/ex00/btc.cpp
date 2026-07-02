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

void	checkErrorsDate(std::string str)
{
	
}

void	btc::putLineFile(std::string str, std::ifstream& file)
{
	std::string	key = str.substr(0, str.find('|'));
	std::string	value_str = str.substr(str.find('|') + 1, str.length());
	float			value = atof(value_str.c_str());
	if ()
	this->btcData.insert(std::make_pair(key, value));
}

btc::btc()
{
	fillBtcData();
}