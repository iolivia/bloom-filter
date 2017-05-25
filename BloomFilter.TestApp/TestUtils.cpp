#include "stdafx.h"

#include "TestUtils.h"

BloomFilter TestUtils::CreateBloomFilter(int size, int k)
{
	auto hash = new Hash();
	auto bloomFilter = BloomFilter(*hash, size, k);

	return bloomFilter;
}