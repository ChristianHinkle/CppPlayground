// Copyright (c) 2026 Christian Hinkle.

#include <vector>
#include <queue>

// Note: We use a min heap to be more efficient with space as well as keep things more simple. With the
// min heap, we have it only storing the `k` largest values, which means that the top of it represents the
// `k`th largest. If we used a max heap, we would have to pop from it until we reach the `k`th largest, and then
// re-push each one that we popped to preserve the data for the next function calls. That would be very complex
// unnecessary.
class KthLargest
{
public:
    KthLargest(int k, std::vector<int>& nums)
        : m_numsMinHeap{nums.begin(), nums.end()}
        , m_k{k}
    {
        // The min heap should contain exactly `k` amount of elements. If there are more, pop until it matches.
        while (m_numsMinHeap.size() > m_k)
        {
            m_numsMinHeap.pop();
        }
    }

    int add(int val)
    {
        return addImpl(m_k, m_numsMinHeap, val);
    }

private:
    static int addImpl(int k, std::priority_queue<int, std::vector<int>, std::greater<int>>& numsMinHeap, int val)
    {
        // Note: The top of the min heap is the `k`th largest element.

        if (numsMinHeap.size() < k)
        {
            numsMinHeap.push(val);
        }
        else
        {
            // If this new value is larger than the `k`th largest, then push it into the top `k` largest elements min heap, and pop the old `k`th largest.
            if (val > numsMinHeap.top())
            {
                numsMinHeap.pop();
                numsMinHeap.push(val);
            }
        }

        // Return the new `k`th largest.
        return numsMinHeap.top();
    }

private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> m_numsMinHeap;
    int m_k{};
};
