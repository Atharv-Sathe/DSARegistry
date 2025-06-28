#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

/*
  This is an advanced version of Number of Distinct Islandes problem
  refer (NumberOfDistinctIslands.cpp) as it assumes that two islands
  which are interconvertible using the 8 tranformations are equal and
  not distinct.
*/

#define all(x) x.begin(), x.end()

using Coord = pair<int, int>;
using Shape = vector<Coord>;
vector<pair<int, int>> dirc{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

set<Shape> signatures;

// Get the coordinates of an island
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

// Apply tranformations
void applyTransformations(Shape& island) {
  vector<function<Coord(const Coord&)>> ops{
      [](Coord p) -> Coord { return {p.first, p.second}; },    // 0 Deg
      [](Coord p) -> Coord { return {p.second, -p.first}; },   // 90 Deg
      [](Coord p) -> Coord { return {-p.first, -p.second}; },  // 180 Deg
      [](Coord p) -> Coord { return {-p.second, p.first}; },   // 270 Deg
      [](Coord p) -> Coord {
        return {p.first, -p.second};
      },  // Horizontal Reflection
      [](Coord p) -> Coord {
        return {-p.first, p.second};
      },  // Vertical Reflection
      [](Coord p) -> Coord {
        return {p.second, p.first};
      },  // Diagonal (BL - TR)
      [](Coord p) -> Coord {
        return {-p.second, -p.first};
      }  // Reverse Diag (TL - BR)
  };

  vector<Shape> transformations;

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

  for (const auto& op : ops) {
    Shape transformed;
    transform(all(island), back_inserter(transformed), op);
    normalize(transformed);
    transformations.push_back(transformed);
  }

  Shape lexoSmallest = *min_element(all(transformations));
  signatures.insert(lexoSmallest);
}

int countDistinctIslands(vector<vector<int>>& grid) {
  int m = grid.size();
  int n = grid[0].size();

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j]) {
        Shape island;
        dfs(grid, i, j, island);
        applyTransformations(island);
      }
    }
  }

  return signatures.size();
}

int main() { return 0; }