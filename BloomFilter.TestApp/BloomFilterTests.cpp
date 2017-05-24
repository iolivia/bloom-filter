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