#include "stdafx.h"

#include "gtest/gtest.h"

#include "../BloomFilter/Hash.cpp"

TEST(Hash, HashIsNotEmpty)
{
	// Arrange
	auto hash = new Hash();
	auto input = "abc";

	// Act
	auto hashedInput = hash->hash(input);

	// Assert
	EXPECT_TRUE(!hashedInput.empty());
}

TEST(Hash, HashIsConsistent)
{
	// Arrange
	auto hash = new Hash();
	auto input = "abc";

	// Act
	auto hashedInput1 = hash->hash(input);
	auto hashedInput2 = hash->hash(input);

	// Assert
	EXPECT_EQ(hashedInput1, hashedInput2);
}

TEST(Hash, DifferentForDifferentInputs)
{
	// Arrange
	auto hash = new Hash();
	auto input1 = "abgfgeasgsgretryhgh456gdfgdfc";
	auto input2 = "fafdfsadggbdfbdfcvb";

	// Act
	auto hashedInput1 = hash->hash(input1);
	auto hashedInput2 = hash->hash(input2);

	// Assert
	EXPECT_NE(hashedInput1, hashedInput2);
}

TEST(HashIterations, EmptyFor0Iterations)
{
	// Arrange
	auto hash = new Hash();
	auto input = "abgfgeasgsgretryhgh456gdfgdfc";
	unsigned int interations = 0;

	// Act
	auto hashedInput = hash->hash(input, interations);

	// Assert
	EXPECT_TRUE(hashedInput.empty());
}

TEST(HashIterations, SameFor1Iteration)
{
	// Arrange
	auto hash = new Hash();
	auto input = "abgfgeasgsgretryhgh456gdfgdfc";
	unsigned int interations = 1;
	auto hashedInputOnce = hash->hash(input);

	// Act
	auto hashedInput = hash->hash(input, interations);

	// Assert
	EXPECT_EQ(hashedInputOnce, hashedInput);
}

TEST(HashIterations, DifferentForManyIterations)
{
	// Arrange
	auto hash = new Hash();
	auto input = "abgfgeasgsgretryhgh456gdfgdfc";
	unsigned int interations = 10;
	auto hashedInputOnce = hash->hash(input);

	// Act
	auto hashedInput = hash->hash(input, interations);

	// Assert
	EXPECT_NE(hashedInputOnce, hashedInput);
}

TEST(HashIterations, DifferentForDifferentIterations)
{
	// Arrange
	auto hash = new Hash();
	auto input = "abgfgeasgsgretryhgh456gdfgdfc";
	unsigned int interations1 = 10;
	unsigned int interations2 = 5;

	// Act
	auto hashedInput1 = hash->hash(input, interations1);
	auto hashedInput2 = hash->hash(input, interations2);

	// Assert
	EXPECT_NE(hashedInput1, hashedInput2);
}

TEST(HashIterationsMax, NotAboveMax)
{
	// Arrange
	auto hash = new Hash();
	auto input = "abgfgeasgsgretryhgh456gdfgdfc";
	unsigned int interations = 10;
	unsigned int max = 100;

	// Act
	unsigned int hashedInput = hash->hash(input, interations, max);

	// Assert
	EXPECT_LE(hashedInput, max);
}