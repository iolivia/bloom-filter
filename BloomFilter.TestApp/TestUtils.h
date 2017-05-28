#pragma once

#include <string>
#include <vector>

#include "../BloomFilter/src/BloomFilter.h"

namespace TestUtils
{
	std::vector<std::string> GenerateRandomStrings(int length, int count);
	std::string GetCurrentDateTime();
}