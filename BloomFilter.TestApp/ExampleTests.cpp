#include "stdafx.h"

#include "gtest/gtest.h"

#include "../BloomFilter/src/Bloom/BloomFilter.h"

using namespace Bloom;

TEST(Examples, CreateFilterPutGet)
{
	// Create the filter
	int size = 10000; // the size of the filter - i.e. number of underlying bits used
	int k = 3; // the number of hashing functions to use
	auto bloomFilter = BloomFilter(size, k);

	// Put items in
	bloomFilter.put("ABC");
	bloomFilter.put("JKDJKD");
	bloomFilter.put("UDIG");

	// Check if items are present
	bool isMaybePresent;
	
	isMaybePresent = bloomFilter.isMaybePresent("ABC");
	isMaybePresent = bloomFilter.isMaybePresent("EFG");
}