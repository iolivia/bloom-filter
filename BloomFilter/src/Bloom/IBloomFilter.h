#pragma once

#include <string>

namespace Bloom
{
	class IBloomFilter
	{
	public:
		virtual void put(std::string input) = 0;
		virtual bool isMaybePresent(std::string input) const = 0;
	};
}