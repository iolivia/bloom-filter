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

struct BloomFilterTestRun
{
	int size;
	int k;
	int itemsCount;
	int itemLength;

	BloomFilterTestRun(int size, int k, int itemsCount, int itemLength)
		: size(size)
		, k(k)
		, itemsCount(itemsCount)
		, itemLength(itemLength)
	{
	}
};

void RunFalsePositiveTest(
	std::ofstream& testFile, 
	const BloomFilterTestRun& testRun)
{
	auto itemsPresent = GenerateRandomStrings(testRun.itemLength, testRun.itemsCount);
	auto itemsNotPreset = GenerateRandomStrings(testRun.itemLength, testRun.itemsCount);
	auto bloomFilter = CreateBloomFilter(testRun.size, testRun.k);

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

	auto errorRate = falsePositive / (testRun.itemsCount * 1.0);
	testFile << testRun.size << " " << testRun.k << " " << testRun.itemsCount << " " << errorRate << " \n";
}

TEST(Performance, FalsePositiveRate)
{
	// Setup
	std::ofstream testFile;
	testFile.open("false_positives.txt");

	auto testRuns = 
	{
		// Fixed size, fixed items, change k
		BloomFilterTestRun(10000, 1, 500, 3),
		BloomFilterTestRun(10000, 3, 500, 3),
		BloomFilterTestRun(10000, 5, 500, 3),
		BloomFilterTestRun(10000, 10, 500, 3),
		BloomFilterTestRun(10000, 20, 500, 3),
		BloomFilterTestRun(10000, 25, 500, 3),
		BloomFilterTestRun(10000, 30, 500, 3),
		BloomFilterTestRun(10000, 50, 500, 3),
		BloomFilterTestRun(10000, 100, 500, 3),
		BloomFilterTestRun(10000, 300, 500, 3),
	};

	for (const auto& testRun : testRuns)
	{
		RunFalsePositiveTest(testFile, testRun);
	}

	// Cleanup 
	testFile.close();
}