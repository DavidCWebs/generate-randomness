#include <iostream>
#include <fstream>
#include <vector>
#include <fstream>
#include <iterator>
#include <iomanip>

int main()
{

	int n = 0;
	std::cout << "Enter the number of random bytes to fetch from /dev/urandom:" << '\n';
	if (!(std::cin >> n)) {
		std::cout << "Not an integer. Exiting..." << '\n';
		return 1;	
	}
	std::ifstream file("/dev/urandom", std::ios::binary|std::ios::in);
	if (!file) {
		std::cerr << "Couldn't open /dev/urandom. Exiting..." << '\n';
		return 1;
	}
	std::vector<char> randomBytes(n);
	file.read(&randomBytes[0], n);
	for (auto& el : randomBytes)
		std::cout << std::setfill('0') << std::setw(2) << std::hex << (0xff & (unsigned int)el);
	std::cout << '\n';
	return 0;
}
