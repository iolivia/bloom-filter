#pragma once

namespace TestUtils
{
	BloomFilter CreateBloomFilter(int size, int k);
	std::vector<std::string> GenerateRandomStrings(int length, int count);
}