// Copyright (c) 2026 Christian Hinkle.

#include <vector>
#include <tuple>
#include <cassert>

class Solution
{
public:
    static bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target)
    {
        assert(!matrix.empty()); // This must be true, according to the constraints.

        const std::size_t m = matrix.size();
        const std::size_t n = matrix.front().size();

        const std::size_t size = m * n;

        std::size_t begin = 0u;
        std::size_t end = size;

        while (end - begin > 0)
        {
            const std::size_t rangeSize = end - begin;
            const std::size_t midIndex = begin + (rangeSize / 2);
            const auto [rowIndex, valueIndex] = indexTo2dIndices(midIndex, m, n); // Convert the index to 2d array coordinates.

            const int midValue = matrix.at(rowIndex).at(valueIndex);

            if (target < midValue)
            {
                end = midIndex;
                continue;
            }

            if (target > midValue)
            {
                begin = midIndex + 1;
                continue;
            }

            // Target is equal!
            return true;
        }

        return false;
    }

private:
    constexpr static std::tuple<std::size_t, std::size_t> indexTo2dIndices(std::size_t index, std::size_t m, std::size_t n)
    {
        std::size_t rowIndex = index / n;
        std::size_t valueIndex = index % n;

        return std::tuple{rowIndex, valueIndex};
    }
};
