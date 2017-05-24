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

int Hash::hash(int iterations) const
{
	return 0;
}
