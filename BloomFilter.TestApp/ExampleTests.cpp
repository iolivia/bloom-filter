#include "stdafx.h"

#include "gtest/gtest.h"

#include "../BloomFilter/BloomFilter.cpp"

using namespace TestUtils;

TEST(BloomFilter, Put)
{
	// Arrange
	int size = 10;
	int k = 3;
	auto hash = new Hash();
	auto bloomFilter = BloomFilter(*hash, size, k);

	auto bloomFilter = CreateBloomFilter(size, k);

	std::string input = "A";

	// Act
	bloomFilter.put(input);
}