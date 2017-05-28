#pragma once

#include <vector>

#include "Hash.h"
#include "IBloomFilter.h"

class BloomFilter : public IBloomFilter {

public:
	BloomFilter(const Hash& hash, int size, int k);
	BloomFilter(int size, int k);

	// Inherited via IBloomFilter
	virtual void put(std::string input) override;
	virtual bool isMaybePresent(std::string input) const override;

private:
	Hash m_hash;
	int m_k;
	std::vector<bool> m_vector;
};