#pragma once

#include "IBloomFilter.h"

class BloomFilter : public IBloomFilter {
	// Inherited via IBloomFilter
	virtual void put(std::string input) override;
	virtual bool isMaybePresent(std::string input) override;
};