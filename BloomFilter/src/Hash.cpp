#include <array>

#include "Hash.h"

#include "..\include\MurmurHash3.h"

std::array<uint32_t, 2> Hash::hash(const std::string & input) const
{
	// generate the hex hash of the input
	std::array<uint32_t, 2> out;
	MurmurHash3_x86_32(input.data(), sizeof(input.data()), 0, out.data());

	return out;
}

std::vector<size_t> Hash::hash(
	const std::string& input, 
	unsigned int iterations, 
	size_t max) const
{
	auto hashesIndexed = std::vector<size_t>();
	auto hashedInput = this->hash(input);
	auto firstHash = hashedInput[0];
	auto secondHash = hashedInput[0];

	for (unsigned int i = 0; i < iterations; i++)
	{
		auto hashedInputInt = (firstHash + secondHash * i) % max;
		hashesIndexed.push_back(hashedInputInt);
	}

	return hashesIndexed;
}