#include "stdafx.h"

#include "gtest/gtest.h"

#include "../BloomFilter/Hash.cpp"
#include "../BloomFilter/lib/MurmurHash3.cpp"
//
//TEST(Hash, HashIsNotEmpty)
//{
//	// Arrange
//	auto hash = new Hash();
//	auto input = "abc";
//
//	// Act
//	auto hashedInput = hash->hash(input);
//
//	// Assert
//	EXPECT_TRUE(!hashedInput.empty());
//}
//
//TEST(Hash, HashIsConsistent)
//{
//	// Arrange
//	auto hash = new Hash();
//	auto input = "abc";
//
//	// Act
//	auto hashedInput1 = hash->hash(input);
//	auto hashedInput2 = hash->hash(input);
//
//	// Assert
//	EXPECT_EQ(hashedInput1, hashedInput2);
//}
//
//TEST(Hash, DifferentForDifferentInputs)
//{
//	// Arrange
//	auto hash = new Hash();
//	auto input1 = "abgfgeasgsgretryhgh456gdfgdfc";
//	auto input2 = "fafdfsadggbdfbdfcvb";
//
//	// Act
//	auto hashedInput1 = hash->hash(input1);
//	auto hashedInput2 = hash->hash(input2);
//
//	// Assert
//	EXPECT_NE(hashedInput1, hashedInput2);
//}
//
//TEST(HashIterations, EmptyFor0Iterations)
//{
//	// Arrange
//	auto hash = new Hash();
//	auto input = "abgfgeasgsgretryhgh456gdfgdfc";
//	unsigned int interations = 0;
//
//	// Act
//	auto hashedInput = hash->hash(input, interations);
//
//	// Assert
//	EXPECT_TRUE(hashedInput.empty());
//}
//
//TEST(HashIterations, SameFor1Iteration)
//{
//	// Arrange
//	auto hash = new Hash();
//	auto input = "abgfgeasgsgretryhgh456gdfgdfc";
//	unsigned int interations = 1;
//	auto hashedInputOnce = hash->hash(input);
//
//	// Act
//	auto hashedInput = hash->hash(input, interations);
//
//	// Assert
//	EXPECT_EQ(hashedInputOnce, hashedInput[0]);
//}
//
//TEST(HashIterations, DifferentForDifferentIterations)
//{
//	// Arrange
//	auto hash = new Hash();
//	auto input = "abgfgeasgsgretryhgh456gdfgdfc";
//	unsigned int iterations = 10;
//
//	// Act
//	auto hashedInput = hash->hash(input, iterations);
//
//	// Assert
//	EXPECT_NE(hashedInput[iterations - 2], hashedInput[iterations - 1]);
//}
//
//TEST(HashIterationsMax, NotAboveMax)
//{
//	// Arrange
//	auto hash = new Hash();
//	auto input = "abgfgeasgsgretryhgh456gdfgdfc";
//	unsigned int interations = 10;
//	unsigned int max = 100;
//
//	// Act
//	auto hashedIndexed = hash->hash(input, interations, max);
//
//	// Assert
//	for (const auto& hashedIndex : hashedIndexed) 
//	{
//		EXPECT_LE(hashedIndex, max);
//	}
//}