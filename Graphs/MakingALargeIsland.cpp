#include <bits/stdc++.h>
using namespace std;

/*
  You are given an n x n binary matrix grid. You are allowed to change at most
  one 0 to be 1.

  Return the size of the largest island in grid after applying this operation.

  An island is a 4-directionally connected group of 1s.
*/

int find(int n, vector<int>& par) {
  int root = n;
  while (root != par[root]) {
    root = par[root];
  }

  while (n != par[n]) {
    int next = par[n];
    par[n] = root;
    n = next;
  }
  return root;
}

void connect(int a, int b, vector<int>& par, vector<int>& size) {
  int root1 = find(a, par);
  int root2 = find(b, par);

  if (root1 == root2) return;

  if (size[root1] < size[root2]) {
    size[root2] += size[root1];
    par[root1] = root2;
  } else {
    size[root1] += size[root2];
    par[root2] = root1;
  }
}

int largestIsland(vector<vector<int>>& grid) {
  int n = grid.size();
  vector<int> par(n * n);
  iota(par.begin(), par.end(), 0);
  vector<int> size(n * n, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 0) continue;

      int id = i * n + j;

      if (size[id] == 0) size[id] = 1;  // Every valid node has a size of 1

      if (i > 0 && grid[i - 1][j]) {
        int id2 = (i - 1) * n + j;
        connect(id, id2, par, size);
      }

      if (j > 0 && grid[i][j - 1]) {
        int id2 = i * n + (j - 1);
        connect(id, id2, par, size);
      }
    }
  }

  int maxSize = *max_element(size.begin(), size.end());
  if (maxSize == n * n) return maxSize;

  int dx[]{0, 1, 0, -1};
  int dy[]{1, 0, -1, 0};

  // Second pass
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 0) {
        unordered_map<int, int> islandToSize;

        for (int k = 0; k < 4; k++) {
          int nxtR = i + dx[k];
          int nxtC = j + dy[k];

          if (nxtR < 0 || nxtR >= n || nxtC < 0 || nxtC >= n ||
              !grid[nxtR][nxtC])
            continue;

          int islandRoot = find(nxtR * n + nxtC, par);
          islandToSize[islandRoot] = size[islandRoot];
        }

        int newSize = 1;
        for (auto& p : islandToSize) {
          newSize += p.second;
        }
        maxSize = max(maxSize, newSize);
      }
    }
  }

  return maxSize;
}

int main() { return 0; }