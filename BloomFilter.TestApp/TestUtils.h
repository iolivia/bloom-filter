#pragma once

#include "../BloomFilter/BloomFilter.h"

namespace TestUtils
{
	BloomFilter CreateBloomFilter(int size, int k);
}