#include "BloomFilter.h"

BloomFilter::BloomFilter(const Hash & hash, size_t size, int k)
	: m_hash(hash)
	, m_k(k)
	, m_vector(size)
{
}

BloomFilter::BloomFilter(size_t size, int k)
	: BloomFilter(Hash(), size, k)
{
}

void BloomFilter::put(std::string input)
{
	// Hash and get k indexes
	auto& indexes = m_hash.hash(input, m_k, m_vector.size());

	// Set all those bits to 1
	for (const auto& index : indexes)
	{
		m_vector[index] = true;
	}
}

bool BloomFilter::isMaybePresent(std::string input) const
{
	// Hash and get k indexes
	auto& indexes = m_hash.hash(input, m_k, m_vector.size());

	// Find if all bits are set
	for (const auto& index : indexes)
	{
		if (m_vector[index] == false)
		{
			return false;
		}
	}

	return true;
}