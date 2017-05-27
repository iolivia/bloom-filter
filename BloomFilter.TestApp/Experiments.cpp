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

void RunPerformanceTest(const std::string& fileName, const std::vector<BloomFilterTestRun>& testRuns)
{
	// Setup
	std::ofstream testFile;
	testFile.open(fileName);

	for (const auto& testRun : testRuns)
	{
		RunFalsePositiveTest(testFile, testRun);
	}

	// Cleanup 
	testFile.close();
}

void RunOptimalKTest(std::string fileName, int itemsCount)
{
	int filterSize = 10000;
	int kStart = 1;
	int kEnd = filterSize / 2;
	int kBuckets = 100;
	int itemLength = 3;

	auto ks = 
	{
		1,
		3,
		5,
		10,
		15,
		20,
		50,
		200,
		500
	};

	std::vector<BloomFilterTestRun> testRuns;

	// Iterate through all Ks 
	for (const int& k : ks)
	{
		testRuns.push_back(BloomFilterTestRun(filterSize, k, itemsCount, itemLength));
	}

	RunPerformanceTest(fileName, testRuns);
}

TEST(Performance, FalsePositiveRate_OptimalK_500items)
{
	RunOptimalKTest("FalsePositiveRate_OptimalK_500items.txt", 500);
}

TEST(Performance, FalsePositiveRate_OptimalK_200items)
{
	RunOptimalKTest("FalsePositiveRate_OptimalK_200items.txt", 200);
}