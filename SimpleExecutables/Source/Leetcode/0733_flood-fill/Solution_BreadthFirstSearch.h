// Copyright (c) 2026 Christian Hinkle.

#include <vector>
#include <cassert>
#include <queue>

/**
 * Breadth-first search implementation of solution.
 */
class Solution
{
public:
    static std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color);
};

std::vector<std::vector<int>> Solution::floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color)
{
    const std::size_t numRows = image.size();

    // Do nothing if the column index is out of bounds.
    if (sr < 0 || sr >= numRows)
    {
        return image;
    }

    assert(numRows > 0); // If we got passed the index checks, then we know the array is not empty.

    const std::size_t numColumns = image[0].size();

    // Do nothing if the row index is out of bounds.
    if (sc < 0 || sc >= numColumns)
    {
        return image;
    }

    assert(numColumns > 0); // If we got passed the index checks, then we know the array is not empty.

    const int startingColor = image[sr][sc];

    // Note: We copy it here to respect the caller's lvalue ref. We should not move it as the return value.
    auto newImage = image;

    struct RowColumnPair
    {
        int r{};
        int c{};
    };

    std::queue<RowColumnPair> pixelQueue;

    pixelQueue.emplace(sr, sc);
    while (!pixelQueue.empty())
    {
        RowColumnPair currentPixelCoordinate = pixelQueue.front();
        pixelQueue.pop();

        if (currentPixelCoordinate.r < 0 || currentPixelCoordinate.r >= numRows)
        {
            continue;
        }

        if (currentPixelCoordinate.c < 0 || currentPixelCoordinate.c >= numColumns)
        {
            continue;
        }

        int& currentPixelValue = newImage[currentPixelCoordinate.r][currentPixelCoordinate.c];

        if (currentPixelValue == color)
        {
            // The current pixel is already filled, so do not search further.
            continue;
        }

        if (currentPixelValue != startingColor)
        {
            // The current pixel should not be filled, and we should not search further.
            continue;
        }

        // Set this current pixel.
        currentPixelValue = color;

        // Now, enqueue our neighboring pixels:
        pixelQueue.emplace(currentPixelCoordinate.r - 1, currentPixelCoordinate.c);
        pixelQueue.emplace(currentPixelCoordinate.r + 1, currentPixelCoordinate.c);
        pixelQueue.emplace(currentPixelCoordinate.r, currentPixelCoordinate.c - 1);
        pixelQueue.emplace(currentPixelCoordinate.r, currentPixelCoordinate.c + 1);
    }

    return newImage;
}
