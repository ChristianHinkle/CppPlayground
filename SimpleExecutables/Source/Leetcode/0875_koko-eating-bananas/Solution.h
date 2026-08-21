// Copyright (c) 2026 Christian Hinkle.

#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdlib>

class Solution
{
public:
    static int minEatingSpeed(const std::vector<int>& piles, int h)
    {
        int lowerBound = 1;
        int upperBound = std::ranges::max(piles);

        while (upperBound - lowerBound >= 0)
        {
            const int testSpeed = lowerBound + (upperBound - lowerBound) / 2;

            const long long comparison = testEatingSpeed(piles, h, testSpeed);

            if (comparison > 0)
            {
                // Took too many hours. Speed it up.
                lowerBound = testSpeed + 1;
            }
            else
            {
                // It we didn't take too long, then let's keep trying to go slower.
                upperBound = testSpeed - 1;
            }
        }

        return lowerBound;
    }

private:
    static long long testEatingSpeed(const std::vector<int>& piles, int h, int speed)
    {
        long long resultingHours = 0;

        for (const int pile : piles)
        {
            // Num bananas in pile divided by speed, rounded up.
            resultingHours += (pile + (speed - 1)) / speed;
        }

        return resultingHours - h;
    }
};
