#include "stdafx.h"

#include "gtest/gtest.h"

#include <iostream>
#include <fstream>
#include <chrono>

#include "TestUtils.h"

using namespace TestUtils;

TEST(Performance, Put)
{
	// Arrange
	std::ofstream testFile;
	testFile.open("put_performance.txt");

	int size = 10000;
	int k = 20;
	int itemsCount = 20;
	int itemLength = 10;
	auto items = GenerateRandomStrings(itemLength, itemsCount);
	auto bloomFilter = CreateBloomFilter(size, k);

	// Act
	for (const auto& item : items)
	{
		auto putStart = std::chrono::high_resolution_clock::now();
		bloomFilter.put(item);
		auto putEnd = std::chrono::high_resolution_clock::now();

		// Print the time it took to put
		auto& ms = std::chrono::duration_cast<std::chrono::milliseconds>(putEnd - putStart);
		testFile << ms.count() << "\n";
	}

	// Cleanup 
	testFile.close();
}

TEST(Performance, FalsePositiveRate)
{
	// Setup
	std::ofstream testFile;
	testFile.open("false_positives.txt");

	int size = 10000;
	int k = 20;
	int itemsCount = 500;
	int itemLength = 3;
	auto itemsPresent = GenerateRandomStrings(itemLength, itemsCount);
	auto itemsNotPreset = GenerateRandomStrings(itemLength, itemsCount);
	auto bloomFilter = CreateBloomFilter(size, k);

	// Put itemsPresent
	for (const auto& item : itemsPresent)
	{
		bloomFilter.put(item);
	}

	// Query for itemsNotPreset to get the true/false positive rate
	auto falsePositive = 0;
	for (const auto& item : itemsNotPreset)
	{
		bool isMaybePresent = bloomFilter.isMaybePresent(item);
		falsePositive += isMaybePresent;
	}

	auto errorRate = falsePositive / (itemsCount * 1.0);
	testFile << "error rate: " << errorRate << " \n";

	// Cleanup 
	testFile.close();
}