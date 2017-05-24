#pragma once

#include <string>

class Hash {
public:
	std::string hash(const std::string& input) const;
	int hash(int iterations) const;
};