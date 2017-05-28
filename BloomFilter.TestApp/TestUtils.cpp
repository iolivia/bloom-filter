#include "stdafx.h"

#include <algorithm>
#include <iterator>
#include <iostream>
#include <ctime>

#include "TestUtils.h"

std::string generateRandomString(size_t length)
{
	const char* charmap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const size_t charmapLength = strlen(charmap);
	auto generator = [&]() { return charmap[rand() % charmapLength]; };
	std::string result;
	result.reserve(length);
	std::generate_n(std::back_inserter(result), length, generator);

	return result;
}

std::vector<std::string> TestUtils::GenerateRandomStrings(int length, int count)
{
	std::vector<std::string> strings;

	for (int i = 0; i < count; i++)
	{
		strings.push_back(generateRandomString(length));
	}

	return strings;
}

std::string TestUtils::GetCurrentDateTime()
{
	time_t t = time(NULL);
	struct tm buf;
	char str[26];
	auto time = localtime_s(&buf, &t);
	asctime_s(str, sizeof str, &buf);

	std::string tString(str);

	return tString;
}
