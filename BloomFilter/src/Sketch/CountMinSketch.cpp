#include "CountMinSketch.h"

using namespace Sketch;

CountMinSketch::CountMinSketch(
	const size_t rows, 
	const size_t cols, 
	const Hash& hash)
	: m_vector()
	, m_hash(hash)
{
	for (size_t row = 0; row < rows; row++)
	{
		m_vector.push_back(std::vector<uint32_t>(cols));
	}
}

CountMinSketch::CountMinSketch(
	const size_t rows, 
	const size_t cols)
	: CountMinSketch(rows, cols, Hash())
{
}

void CountMinSketch::insert(const std::string & key)
{
}

uint32_t CountMinSketch::getFrequency(const std::string & key) const
{
	return uint32_t();
}
