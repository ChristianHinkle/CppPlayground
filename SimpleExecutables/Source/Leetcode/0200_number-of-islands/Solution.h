// Copyright (c) 2026 Christian Hinkle.

#include <vector>
#include <queue>
#include <cassert>

/**
 * ## Algorithm
 *
 * Breadth-first search.
 *
 * ## Time complexity
 *
 * Average/worst/best case: O(n * m)
 *
 * Because we are breadth-first searching all the tiles of each island, which, in the worst
 * case, is all of the tiles in the entire grid. This would cause that many BFS loop iterations.
 *
 * On top of that, we iterate over the entire n-by-m-sized grid anyway. So that is
 * another n * m. (This just adds a factor of 2 which gets dominated by the larger growth of n and m.)
 *
 * ## Space complexity
 *
 * Average/worst/best case: O(n * m)
 *
 * Because we are breadth-first searching all the tiles of each island, which, in the worst
 * case, is all of the tiles in the entire grid. This would cause that many BFS jobs to be queued. This would
 * still be the case with a recursive depth-first search solution as well, just on the stack instead, because
 * each tile to explore would add a stack frame of the recursive call.
 *
 * On top of that, the n-by-m-sized grid is copied. So that is
 * another n * m. (This just adds a factor of 2 which gets dominated by the larger growth of n and m.)
 */
class Solution
{
public:
    static int numIslands(std::vector<std::vector<char>>& grid)
    {
        assert(!grid.empty()); // True according to problem's constraints.

        const std::size_t m = grid.size();
        const std::size_t n = grid.at(0).size();

        int result{};

        {
            // Copy the grid so we can mutate it and store data per tile.
            std::vector<std::vector<char>> gridToFloodFill = grid;

            // Iterate over the entire grid, looking for unsearched tiles of land that we can explore to
            // increment our `result` islands counter.
            for (std::size_t y = 0u; y < m; ++y)
            {
                for (std::size_t x = 0u; x < n; ++x)
                {
                    const char& tile = gridToFloodFill[y][x];

                    assert(tile == '0' || tile == '1'); // True according to problem's constraints.

                    // We have stumbled upon a tile of land. Increment the number of islands, and fill the island with
                    // water so that we don't attempt to re-explore it in future iterations.
                    if (tile == '1')
                    {
                        ++result;
                        floodFillLandToWater(gridToFloodFill, y, x);
                    }
                }
            }
        }

        return result;
    }

    static void floodFillLandToWater(std::vector<std::vector<char>>& grid, const std::size_t startY, const std::size_t startX)
    {
        // Assert non-empty grid input.
        assert(!grid.empty());
        assert(!grid.at(0).empty());

        const std::size_t m = grid.size();
        const std::size_t n = grid.at(0).size();

        // Assert valid coords.
        assert(startY < m);
        assert(startX < n);

        // We assume the start tile is a piece of land.
        assert(grid.at(startY).at(startX) == '1');

        struct Coord
        {
            std::size_t y{};
            std::size_t x{};
        };

        // Breadth-first search using a queue.
        std::queue<Coord> coordQueue;
        coordQueue.emplace(startY, startX);

        while (!coordQueue.empty())
        {
            const Coord currentCoord = coordQueue.front();
            coordQueue.pop();

            char& currentTile = grid[currentCoord.y][currentCoord.x];

            if (currentTile != '1')
            {
                continue;
            }

            // Set this tile to water.
            currentTile = '0';

            // Enqueue this tile's neighbors:

            if (currentCoord.y - 1 != static_cast<std::size_t>(-1))
            {
                coordQueue.emplace(currentCoord.y - 1, currentCoord.x);
            }

            if (currentCoord.x - 1 != static_cast<std::size_t>(-1))
            {
                coordQueue.emplace(currentCoord.y, currentCoord.x - 1);
            }

            if (currentCoord.x + 1 < n)
            {
                coordQueue.emplace(currentCoord.y, currentCoord.x + 1);
            }

            if (currentCoord.y + 1 < m)
            {
                coordQueue.emplace(currentCoord.y + 1, currentCoord.x);
            }
        }
    }
};
