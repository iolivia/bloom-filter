#include "Stdafx.h"

#include "BloomFilter.h"

BloomFilter::BloomFilter(int size, std::vector<hashingFunction>& hashingFunctions)
	: m_hashingFunctions(hashingFunctions)
	, m_vector(size)
{
}

void BloomFilter::put(std::string input)
{
}

bool BloomFilter::isMaybePresent(std::string input) const
{
	return false;
}
