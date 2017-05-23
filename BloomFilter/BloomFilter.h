#pragma once

#include <vector>

#include "IBloomFilter.h"

class BloomFilter : public IBloomFilter {

public:
	// Inherited via IBloomFilter
	virtual void put(std::string input) override;
	virtual bool isMaybePresent(std::string input) const override;

private:
	std::vector<bool> m_vector;
};