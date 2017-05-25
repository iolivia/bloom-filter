#pragma once

#include <string>
#include <vector>

#include "../BloomFilter/BloomFilter.h"

namespace TestUtils
{
	BloomFilter CreateBloomFilter(int size, int k);
	std::vector<std::string> GenerateRandomStrings(int length, int count);
	std::string GetCurrentDateTime();
}