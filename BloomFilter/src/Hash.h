#pragma once

#include <string>
#include <vector>

class Hash {
public:
	std::array<uint32_t, 2> hash(const std::string& input) const;
	std::vector<uint32_t> hash(const std::string& input, unsigned int iterations, unsigned int max) const;
};