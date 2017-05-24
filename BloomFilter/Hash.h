#pragma once

#include <string>

class Hash {
public:
	std::string hash(const std::string& input) const;
	std::string hash(const std::string& input, unsigned int iterations) const;
	unsigned int hash(const std::string& input, unsigned int iterations, unsigned int max) const;

private:
	unsigned int convertToInt(const std::string& input, unsigned int max) const;
};