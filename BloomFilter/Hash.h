#pragma once

#include <string>
#include <vector>

class Hash {
public:
	std::string hash(const std::string& input) const;
	std::vector<std::string> hash(const std::string& input, unsigned int iterations) const;
	std::vector<unsigned int> hash(const std::string& input, unsigned int iterations, unsigned int max) const;

private:
	unsigned int convertToInt(const std::string& input, unsigned int max) const;
};