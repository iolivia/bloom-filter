#pragma once

#include <vector>

#include "IBloomFilter.h"

typedef void(*hashingFunction)(std::string a);

class BloomFilter : public IBloomFilter {

public:
	BloomFilter(int size, std::vector<hashingFunction>&);

	// Inherited via IBloomFilter
	virtual void put(std::string input) override;
	virtual bool isMaybePresent(std::string input) const override;

private:
	std::vector<hashingFunction> m_hashingFunctions;
	std::vector<bool> m_vector;
};