#pragma once

# include <fstream>
# include <iostream>
# include <map>
# include <string>
# include <stdio.h>
# include <sstream>
# include <cstdlib>

class	btc
{
	private:
		void							putLineFile(std::string, std::ifstream& file);
		void							putLineData(std::string);
		void							fillBtcData();
	public:
		std::map<std::string, float>	btcData;
		std::map<std::string, float>	filedata;
		bool							cmpDate(std::string date1, std::string date2)const;
		btc();
		btc(const btc& src);
		~btc();
		void							fillFileData(char* filename);
		void							print_btc();
		class DateYearNotValid: public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};
	class DateMonthNotValid: public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};
	class DateDayNotValid: public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};
};

void	checkErrorsDate(std::string str);
std::ostream&	operator<<(std::ostream& os, const btc& BTC);