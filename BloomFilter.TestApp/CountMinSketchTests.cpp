#include "stdafx.h"

#include "gtest/gtest.h"

#include "TestUtils.h"

#include "../BloomFilter/src/Sketch/ISketch.h"
#include "../BloomFilter/src/Sketch/CountMinSketch.h"

using namespace Sketch;

TEST(Sketch, Insert)
{
	// Arrange
	size_t rows = 10;
	size_t cols = 20;
	auto sketch = CountMinSketch(rows, cols);

	std::string eventKey = "A";

	// Act
	sketch.insert(eventKey);
}

TEST(Sketch, InsertMany)
{
	// Arrange
	size_t rows = 10;
	size_t cols = 20;
	auto sketch = CountMinSketch(rows, cols);

	size_t numberOfKeys = 20;
	auto eventKeys = TestUtils::GenerateRandomStrings(5, numberOfKeys);

	size_t maxFrequency = 30;
	auto eventFrequencies = TestUtils::GenerateRandomNumbers(numberOfKeys, maxFrequency);

	// Act
	for (size_t keyIdx = 0; keyIdx < numberOfKeys; keyIdx++)
	{
		auto& key = eventKeys[keyIdx];
		auto keyFrequency = eventFrequencies[keyIdx];

		for (size_t i = 0; i < keyFrequency; i++)
		{
			sketch.insert(key);
		}
	}

	// Assert
	std::vector<size_t> diffs;
	for (size_t keyIdx = 0; keyIdx < numberOfKeys; keyIdx++)
	{
		auto& key = eventKeys[keyIdx];
		auto keyFrequency = eventFrequencies[keyIdx];

		auto frequency = sketch.getFrequency(key);

		auto diff = frequency - keyFrequency;
		diffs.push_back(diff);
	}
}

TEST(Sketch, GetFrequencyZero)
{
	// Arrange
	size_t rows = 10;
	size_t cols = 20;
	auto sketch = CountMinSketch(rows, cols);

	std::string eventKey = "A";

	// Act
	auto frequency = sketch.getFrequency(eventKey);

	// Assert
	ASSERT_EQ(0, frequency);
}