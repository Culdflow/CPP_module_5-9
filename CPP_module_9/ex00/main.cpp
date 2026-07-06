#include "btc.hpp"

int main(int argc, char** argv)
{
	btc BTC;

	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (0);
	}
	BTC.fillFileData(argv[1]);
	return (0);
}