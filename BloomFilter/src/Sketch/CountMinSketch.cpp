#include "CountMinSketch.h"

using namespace Sketch;

CountMinSketch::CountMinSketch(
	const size_t rows, 
	const size_t cols, 
	const Hash& hash)
	: m_rows(rows)
	, m_cols(cols)
	, m_hash(hash)
	, m_vector()
{
	for (size_t row = 0; row < m_rows; ++row)
	{
		m_vector.push_back(std::vector<uint32_t>(m_cols));
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
	for (size_t row = 0; row < m_rows; ++row)
	{
		// Hash 
		auto k = m_hash.hashIteration(key, row, m_cols);

		// Increment
		++(m_vector[row][k]);
	}
}

uint32_t CountMinSketch::getFrequency(const std::string & key) const
{
	size_t minFrequency = std::numeric_limits<std::size_t>::max();

	for (size_t row = 0; row < m_rows; ++row)
	{
		// Hash 
		auto k = m_hash.hashIteration(key, row, m_cols);

		// Find min 
		auto currentFrequency = m_vector[row][k];

		if (currentFrequency < minFrequency)
		{
			minFrequency = currentFrequency;
		}
	}

	return minFrequency;
}