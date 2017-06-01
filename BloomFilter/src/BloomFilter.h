#pragma once

#include <vector>

#include "Hash.h"
#include "IBloomFilter.h"

class BloomFilter : public IBloomFilter {

public:
	BloomFilter(size_t size, int k);

	// Inherited via IBloomFilter
	virtual void put(std::string input) override;
	virtual bool isMaybePresent(std::string input) const override;

private:
	BloomFilter(const Hash& hash, size_t size, int k);

private:
	Hash m_hash;
	int m_k;
	std::vector<bool> m_vector;
};