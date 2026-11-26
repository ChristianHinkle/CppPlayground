// Copyright (c) 2026 Christian Hinkle.

#include <vector>
#include <cassert>

class Solution
{
public:
    static int search(const std::vector<int>& nums, int target)
    {
        assert(!nums.empty()); // True, according to the problem's constraints.

        // Subrange bounds.
        // End is exclusive (similar to how the ".end()" iterator is exclusive).
        // Taking "end - begin" gives us the size of the subrange.
        std::size_t begin = 0u;
        std::size_t end = nums.size();
        while (end - begin > 0) // While the subrange isn't empty.
        {
            const std::size_t mid = begin + (end - begin) / 2;

            if (target < nums.at(mid))
            {
                // Note: We exclude this current value from the next test.
                end = mid;
                continue;
            }
            else if (target > nums.at(mid))
            {
                // Note: We exclude this current value from the next test.
                begin = mid + 1;
                continue;
            }
            else
            {
                return mid;
            }
        }

        return -1;
    }
};
