// Copyright (c) 2026 Christian Hinkle.

#include <vector>
#include <cassert>

/**
 * Depth-first search implementation of solution.
 */
class Solution
{
public:
    static std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color);

private:
    static void floodFillImpl(std::vector<std::vector<int>>& image, const std::size_t currentRow, const std::size_t currentColumn, const int newColor, const int startingColor);
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
    floodFillImpl(newImage, sr, sc, color, startingColor);
    return newImage;
}

void Solution::floodFillImpl(std::vector<std::vector<int>>& image, const std::size_t currentRow, const std::size_t currentColumn, const int newColor, const int startingColor)
{
    const std::size_t numRows = image.size();
    assert(numRows > 0);
    const std::size_t numColumns = image[0].size();
    assert(numColumns > 0);

    int& currentPixel = image[currentRow][currentColumn];

    if (currentPixel == newColor)
    {
        // The current pixel is already filled, so do not recurse.
        return;
    }

    if (currentPixel != startingColor)
    {
        // The current pixel should not be filled, and we should not recurse.
        return;
    }

    // Set this current pixel.
    currentPixel = newColor;

    // Now, recurse on our neighboring pixels (this is the depth-first search way):

    // Notice that this will cause the algorithm to go as deep as possible to the right until we hit a wall, since it's the first recursive
    // call that will be taken, and it's going to the right.
    if (std::size_t rightColumn = currentColumn + 1; rightColumn < numColumns)
    {
        floodFillImpl(image, currentRow, rightColumn, newColor, startingColor);
    }

    if (std::size_t leftColumn = currentColumn - 1; leftColumn != static_cast<std::size_t>(-1))
    {
        floodFillImpl(image, currentRow, leftColumn, newColor, startingColor);
    }

    if (std::size_t downRow = currentRow + 1; downRow < numRows)
    {
        floodFillImpl(image, downRow, currentColumn, newColor, startingColor);
    }

    if (std::size_t upRow = currentRow - 1; upRow != static_cast<std::size_t>(-1))
    {
        floodFillImpl(image, upRow, currentColumn, newColor, startingColor);
    }
}
