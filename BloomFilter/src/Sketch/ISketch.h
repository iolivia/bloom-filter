#pragma once

#include <string>

namespace Sketch
{
	class ISketch
	{
	public:
		virtual void insert(const std::string& key) = 0;
		virtual uint32_t getFrequency(const std::string& key) = 0;
	};
}