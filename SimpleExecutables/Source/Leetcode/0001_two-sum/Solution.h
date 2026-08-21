// Copyright (c) 2026 Christian Hinkle.

#include <vector>
#include <unordered_map>
#include <cassert>

class Solution
{
public:
    static std::vector<int> twoSum(std::vector<int>& nums, int target);
};

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target)
{
    std::unordered_map<int, std::size_t> numToIndexMap;

#if 0 // Disabled, but here for reference. See inside the next for loop for where this was moved to.
    // Build a mapping from each num to its index.
    for (std::size_t i = 0u; i < nums.size(); ++i)
    {
        numToIndexMap.emplace(nums[i], i);
    }
#endif // 0

    // For each num, look up a potential other num that together get us to the target.
    for (std::size_t i = 0u; i < nums.size(); ++i)
    {
        // Add this element to the mapping of values to indices. We are able to get away with
        // building this map as we go, because of the fact that our solution condition happens when
        // we find a pair of numbers that satisfy the requirements. Since it is a pair of two
        // numbers, it means that if the 2nd number isn't in the map by the time we iterate on the
        // 1st number, then that's okay, because we will eventually iterate on the 2nd number which
        // by that point, the 1st number we know is in the map so they will successfully be paired together
        // in that case.
        numToIndexMap.emplace(nums[i], i);

        int otherRequiredNum = target - nums[i];
        auto foundOtherRequiredNum = numToIndexMap.find(otherRequiredNum);
        if (foundOtherRequiredNum == numToIndexMap.end())
        {
            // No other num found.
            continue;
        }

        std::size_t otherRequiredNumIndex = foundOtherRequiredNum->second;
        if (otherRequiredNumIndex == i)
        {
            // This "other num" is the same index as the current num.
            continue;
        }

        std::vector<int> solution;

        solution.reserve(2u);
        solution.push_back(i);
        solution.push_back(otherRequiredNumIndex);

        return solution;
    }

    // Logically unreachable according to the requirements.
    assert(false);
    std::abort();
}
