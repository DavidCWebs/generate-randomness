#include <iostream>
#include <fstream>
#include <vector>
#include <fstream>
#include <iterator>
#include <iomanip>
#include "random.h"

int main()
{
	// Simple implementation
	// ---------------------
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


	// Use Random class to manage randomness more efficiently
	// ------------------------------------------------------

	// Initialise with a size n, generates vector with n random bytes.
	Random r{10};
	for (auto& el : r.getRandomBytes())
		std::cout << (int)el << " ";
	std::cout << '\n';

	
	// Reset the random bytes - refill the vector from /dev/urandom
	r.setRandomBytes();
	// Write random bytes into a buffer
	std::vector<unsigned char> buf;
	r.getRandomBytes(buf);

	for (auto& el : buf)
		std::cout << (int)el << " ";
	std::cout << '\n';
	
	// If initialised with a vector, fill vector with random values.
	std::vector<unsigned char> v(32);
	Random r2{v};

	for (auto& el : v)
		std::cout << (int)el << " ";
	std::cout << '\n';
	return 0;
}
