#include "stdafx.h"
#include "Hash.h"

#include "picosha2.h"

std::string Hash::hash(const std::string & input) const
{
	// generate the hex hash of the input
	std::string hashedInput;
	picosha2::hash256_hex_string(input, hashedInput);

	return hashedInput;
}

std::string Hash::hash(const std::string& input, unsigned int iterations) const
{
	if (iterations == 0) 
	{
		return std::string();
	}

	// generate a hash of the hash for all iterations
	std::string hashedInput = input;
	for (size_t i = 0; i < iterations; i++)
	{
		hashedInput = this->hash(hashedInput);
	}

	return hashedInput;
}

unsigned int Hash::hash(const std::string& input, unsigned int iterations, unsigned int max) const
{
	// hash for all iterations
	auto hashedHexInput = this->hash(input, iterations);

	// convert to int and max out
	auto hashedInputInt = this->convertToInt(hashedHexInput, max);

	return hashedInputInt;
}

unsigned int Hash::convertToInt(const std::string& input, unsigned int max) const
{
	// convert the nex string to an int
	unsigned int inputInt = std::strtoul(input.c_str(), nullptr, 16);

	// mod with the max
	inputInt %= max;

	return inputInt;
}
