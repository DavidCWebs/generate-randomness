#ifndef RANDOM_H
#define RANDOM_H

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>	// std::generate
#include <functional>	// std::function

class Random
{
public:
	typedef std::vector<unsigned char>::iterator iterator;
	
	Random();
	Random(size_t nBytes);
	Random(std::vector<unsigned char>& buffer);
	void fillVector(std::vector<unsigned char>::iterator initial, std::vector<unsigned char>::iterator final);
	void setRandomBytes();
	void setRandomBytes(iterator start, iterator end);
	std::vector<unsigned char> getRandomBytes() const;
	void getRandomBytes(std::vector<unsigned char>& buffer) const;

private:
	size_t nBytes;
	std::vector<unsigned char> randomBytes;


};

class OpenFileException{};

#endif
