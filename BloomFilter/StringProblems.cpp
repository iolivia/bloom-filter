#include "stdafx.h"

#include <algorithm>

#include "StringProblems.h"

bool Beginner::isAnagram(std::string s1, std::string s2)
{
	// sort both strings
	std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());

	// compare
	return s1 == s2;
}
