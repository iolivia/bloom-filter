// CppArena.TestApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "gtest/gtest.h"

#include "../CppArena/StringProblems.cpp"

using namespace Beginner;

TEST(IsAnagram, EqualStrings)
{
	// Arrange
	auto s1 = "abc";
	auto s2 = "abc";

	// Act
	auto isAnagram = ::isAnagram(s1, s2);

	// Assert
	EXPECT_TRUE(isAnagram);
}

TEST(IsAnagram, Anagram)
{
	// Arrange
	auto s1 = "abc";
	auto s2 = "bca";

	// Act
	auto isAnagram = ::isAnagram(s1, s2);

	// Assert
	EXPECT_TRUE(isAnagram);
}

TEST(IsAnagram, NotAnagram)
{
	// Arrange
	auto s1 = "abc";
	auto s2 = "dasdsa";

	// Act
	auto isAnagram = ::isAnagram(s1, s2);

	// Assert
	EXPECT_FALSE(isAnagram);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}