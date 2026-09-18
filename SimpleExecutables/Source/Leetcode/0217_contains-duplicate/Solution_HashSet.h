// Copyright (c) 2026 Christian Hinkle.

#include <vector>
#include <cassert>
#include <set>

/**
 * ## Time Complexity
 *
 * O(n)
 *
 * We iterate over the entire nums array.
 *
 * ## Space Complexity
 *
 * O(n)
 *
 * We copy each value from the nums array to the set.
 */
class Solution
{
public:
    static bool containsDuplicate(std::vector<int>& nums)
    {
        assert(!nums.empty()); // True, according to problem's constraints.

        std::set<int> numSet;
        for (const int num : nums)
        {
            // If this num is already in the set, then it has occured in a previous iteration, i.e., it is a duplicate.
            if (numSet.contains(num))
            {
                return true;
            }

            numSet.insert(num);
        }

        return false;
    }
};
