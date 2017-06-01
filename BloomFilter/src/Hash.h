#pragma once

#include <string>
#include <vector>

class Hash {
public:
	std::array<uint32_t, 2> hash(const std::string& input) const;
	std::vector<size_t> hash(const std::string& input, unsigned int iterations, size_t max) const;
};