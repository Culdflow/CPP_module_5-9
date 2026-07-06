#include "btc.hpp"

int main(int argc, char** argv)
{
	btc BTC;

	if (argc != 2)
		return (0);
	BTC.fillFileData(argv[1]);
	std::map<std::string, float>::const_iterator it_file;

	std::cout << BTC << std::endl;
	return (0);
}