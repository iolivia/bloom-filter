#include "stdafx.h"

#include <algorithm>
#include <iterator>

#include "TestUtils.h"

std::string generateRandomString(size_t length)
{
	const char* charmap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const size_t charmapLength = strlen(charmap);
	auto generator = [&]() { return charmap[rand() % charmapLength]; };
	std::string result;
	result.reserve(length);
	std::generate_n(std::back_inserter(result), length, generator);

	return result;
}

BloomFilter TestUtils::CreateBloomFilter(int size, int k)
{
	auto hash = new Hash();
	auto bloomFilter = BloomFilter(*hash, size, k);

	return bloomFilter;
}

std::vector<std::string> TestUtils::GenerateRandomStrings(int length, int count)
{
	std::vector<std::string> strings;

	for (int i = 0; i < count; i++)
	{
		strings.push_back(generateRandomString(length));
	}

	return strings;
}
