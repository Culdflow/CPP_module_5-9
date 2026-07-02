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
		std::map<std::string, float>	btcData;
		std::map<std::string, float>	filedata;
		void							putLineFile(std::string, std::ifstream& file);
		void							fillFileData(char* filename);
		void							putLineData(std::string);
		void							fillBtcData();
	public:
		btc();
};