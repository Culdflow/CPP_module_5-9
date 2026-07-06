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
		void							putLineFile(std::string);
		void							putLineData(std::string);
		void							fillBtcData();
	public:
		std::map<std::string, float>	btcData;
		bool							cmpDate(std::string date1, std::string date2)const;
		btc();
		btc(const btc& src);
		btc&	operator=(const btc& src);
		~btc();
		void							fillFileData(char* filename);
};

std::ostream&	operator<<(std::ostream& os, const btc& BTC);