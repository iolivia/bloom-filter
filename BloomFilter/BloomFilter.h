#pragma once

#include <string>

class IBloomFilter 
{
public:
	virtual void put(std::string input) = 0;
	virtual bool isMaybePreset(std::string input) = 0;
};