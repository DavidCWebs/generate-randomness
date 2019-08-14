#include "random.h"


Random::Random()
{

}

// If a size is provided at initialisation, a vector of this size
// is created and filled with random bytes.
Random::Random(size_t n) : nBytes(n), randomBytes(n, 0) 
{
	setRandomBytes();
}

// If a buffer is provided at initialisation, it is filled with random bytes
Random::Random(std::vector<unsigned char>& buffer)
{
	std::cout << "filling provided buffer...\n";
	setRandomBytes(std::begin(buffer), std::end(buffer));	
}

void Random::fillVector(iterator start, iterator end)
{
	setRandomBytes(start, end);
}

// First parameter to read() looks hacky - read stores nBytes characters
// into the array pointed to by first param. To convert the iterator
// into a pointer, get the address of the dereferenced value:
// `&*start`. Then it needs to be cast into a pointer of the correct
// type for `std::ifstream::read()`.
void Random::setRandomBytes(iterator start, iterator end)
{
	size_t nBytes = end - start;
	std::ifstream file("/dev/urandom", std::ios::binary|std::ios::in);
	if (!file)
		throw OpenFileException{};
	
	file.read((char*)&*start, nBytes);
}

// To avoid code duplication, this is a wrapper for
// setRandomBytes(iterator, iterator).
void Random::setRandomBytes()
{
	setRandomBytes(std::begin(randomBytes), std::end(randomBytes));
}

std::vector<unsigned char> Random::getRandomBytes() const
{
	return randomBytes;
}

// If a suitable buffer is provided to the method, passed by reference
// the randomBytes member is copied into the buffer.
void Random::getRandomBytes(std::vector<unsigned char>& buffer) const
{
	buffer = randomBytes;
}

