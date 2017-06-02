#include "stdafx.h"

#include "gtest/gtest.h"

#include "../BloomFilter/src/Sketch/ISketch.h"
#include "../BloomFilter/src/Sketch/CountMinSketch.h"

using namespace Sketch;

TEST(Sketch, Insert)
{
	// Arrange
	int rows = 10;
	int cols = 20;
	auto sketch = CountMinSketch(rows, cols);

	std::string eventKey = "A";

	// Act
	sketch.insert(eventKey);
}

TEST(Sketch, GetFrequencyZero)
{
	// Arrange
	int rows = 10;
	int cols = 20;
	auto sketch = CountMinSketch(rows, cols);

	std::string eventKey = "A";

	// Act
	auto frequency = sketch.getFrequency(eventKey);

	// Assert
	ASSERT_EQ(0, frequency);
}