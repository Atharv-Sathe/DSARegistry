#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
using namespace std;

/**
 * @brief Given a boolean 2D matrix grid of size n * m, finds the number 
 * of distinct islands where a group of connected 1s (horizontally or vertically) 
 * forms an island. Two islands are considered to be distinct if and only if one 
 * island is not equal to another (not rotated or reflected).
 */

using Coord = pair<int, int>; ///< Coordinate pair (row, column)
using Shape = vector<Coord>;  ///< List of coordinates representing an island shape
vector<pair<int, int>> dirc{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; ///< 4-directional movement

set<Shape> signatures; ///< Set to store unique normalized island shapes

/**
 * @brief Performs DFS to collect all coordinates of an island.
 * 
 * @param grid Reference to the 2D grid.
 * @param i Current row index.
 * @param j Current column index.
 * @param island Reference to the vector collecting island coordinates.
 */
void dfs(vector<vector<int>>& grid, int i, int j, Shape& island) {
  int m = grid.size();
  int n = grid[0].size();

  if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return;

  grid[i][j] = 0;
  island.push_back({i, j});

  for (auto direc : dirc) {
    dfs(grid, i + direc.first, j + direc.second, island);
  }
}

/**
 * @brief Counts the number of distinct islands in the grid.
 * 
 * @param grid Reference to the 2D grid.
 * @return int Number of distinct islands.
 */
int countDistinctIslands(vector<vector<int>>& grid) {
  int m = grid.size();
  int n = grid[0].size();

  /**
   * @brief Normalizes the coordinates of an island shape so that its
   * top-leftmost cell is at (0, 0) and sorts the coordinates.
   * 
   * @param transformed Reference to the shape to normalize.
   */
  auto normalize = [](Shape& transformed) {
    int minX = INT_MAX, minY = INT_MAX;
    for (auto Coords : transformed) {
      minX = min(minX, Coords.first);
      minY = min(minY, Coords.second);
    }

    for (auto& Coords : transformed) {
      Coords.first -= minX;
      Coords.second -= minY;
    }

    sort(all(transformed));
  };

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j]) {
        Shape island;
        dfs(grid, i, j, island);
        normalize(island);
        signatures.insert(island);
      }
    }
  }

  return signatures.size();
}

/**
 * @brief Main function (empty, for demonstration purposes).
 * 
 * @return int Always returns 0.
 */
int main() { return 0; }