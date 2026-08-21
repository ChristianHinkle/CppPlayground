// Copyright (c) 2026 Christian Hinkle.

#include <vector>

class Solution
{
public:
    static int search(const std::vector<int>& nums, int target)
    {
        // Begin: Inclusive Index
        // End: Exclusive Index
        std::size_t begin = 0u;
        std::size_t end = nums.size();

        // End - begin = size
        while (end - begin > 0)
        {
            const std::size_t rangeSize = end - begin;
            const std::size_t midIndex = begin + (rangeSize / 2);

            if (target < nums.at(midIndex))
            {
                end = midIndex;
                continue;
            }

            if (target > nums.at(midIndex))
            {
                begin = midIndex + 1;
                continue;
            }

            // Found!
            return midIndex;
        }

        // Not found.
        return -1;
    }
};
