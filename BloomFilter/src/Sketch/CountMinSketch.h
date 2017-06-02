#pragma once

#include <vector>

#include "ISketch.h"

#include "../Hash.h"

namespace Sketch
{
	class CountMinSketch : public ISketch
	{
	public:
		CountMinSketch(
			const size_t rows,
			const size_t cols);

		CountMinSketch(
			const size_t rows, 
			const size_t cols,
			const Hash& hash);

		virtual void insert(const std::string& key) override;
		virtual uint32_t getFrequency(const std::string& key) const override;

	private:
		const size_t m_rows;
		const size_t m_cols;
		const Hash m_hash;
		std::vector<std::vector<uint32_t>> m_vector;
	};
}

