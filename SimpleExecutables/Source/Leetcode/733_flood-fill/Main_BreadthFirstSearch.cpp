// Copyright (c) 2026 Christian Hinkle.

#include <Solution_BreadthFirstSearch.h>
#include <iostream>

void PrintImage(const std::vector<std::vector<int>>& image);

int main()
{
    // [[1,1,1],[1,1,0],[1,0,1]]
    // 1
    // 1
    // 2
    {
        std::vector<std::vector<int>> imageA;
        imageA.reserve(3);

        {
            std::vector<int>& row = imageA.emplace_back();
            row.reserve(3);
            row.push_back(1);
            row.push_back(1);
            row.push_back(1);
        }

        {
            std::vector<int>& row = imageA.emplace_back();
            row.reserve(3);
            row.push_back(1);
            row.push_back(1);
            row.push_back(0);
        }

        {
            std::vector<int>& row = imageA.emplace_back();
            row.reserve(3);
            row.push_back(1);
            row.push_back(0);
            row.push_back(1);
        }

        int srA = 1;
        int scA = 1;

        int colorA = 2;

        std::vector newImage = Solution::floodFill(imageA, srA, scA, colorA);

        std::cout << "Output: ";
        PrintImage(newImage);
        std::cout << '\n';

        std::cout << "Expected: ";
        std::cout << "[[2,2,2],[2,2,0],[2,0,1]]";
        std::cout << '\n';
    }

    return 0;
}

void PrintImage(const std::vector<std::vector<int>>& image)
{
    const std::size_t numRows = image.size();

    if (numRows <= 0)
    {
        std::cout << '[' << ']';
        return;
    }

    const std::size_t numColumns = image[0].size();

    std::cout << '[';
    for (std::size_t c = 0u; c < numColumns; ++c)
    {
        std::cout << '[';
        for (std::size_t r = 0u; r < numRows; ++r)
        {
            std::cout << image[r][c];

            if (r < numRows - 1)
            {
                std::cout << ',';
            }
        }
        std::cout << ']';

        if (c < numColumns - 1)
        {
            std::cout << ',';
        }
    }
    std::cout << ']';
}
