#include "Stdafx.h"


#include "BloomFilter.h"

BloomFilter::BloomFilter(const Hash & hash, int size, int k)
	: m_hash(hash)
	, m_k(k)
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