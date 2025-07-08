#include <bits/stdc++.h>
using namespace std;

/*
  On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point 
  may have at most one stone.

  A stone can be removed if it shares either the same row or the same column as 
  another stone that has not been removed.

  Given an array stones of length n where stones[i] = [xi, yi] represents the 
  location of the ith stone, return the largest possible number of stones that 
  can be removed.

*/

int find(int n, vector<int>& par) {
  int root = n;

  while (root != par[root]) root = par[root];

  while (n != par[root]) {
    int next = par[n];
    par[n] = root;
    n = next;
  }

  return root;
}

void connect(int n1, int n2, vector<int>& par, vector<int>& size) {
  int root1 = find(n1, par);
  int root2 = find(n2, par);

  if (root1 == root2) return;

  if (size[root1] < size[root2]) {
    size[root2] += size[root1];
    par[root1] = root2;
  } else {
    size[root1] += size[root2];
    par[root2] = root1;
  }
}

int removeStones(vector<vector<int>>& stones) {
  int stoneCount = stones.size();

  unordered_map<int, int> rowMap;
  unordered_map<int, int> colMap;
  int id = stoneCount;

  for (int i = 0; i < stoneCount; i++) {
    int row = stones[i][0], col = stones[i][1];

    if (!rowMap.count(row)) {
      rowMap[row] = id++;
    }

    if (!colMap.count(col)) {
      colMap[col] = id++;
    }
  }

  vector<int> par(id);
  iota(par.begin(), par.end(), 0);
  vector<int> size(id, 1);

  for (int i = 0; i < stoneCount; i++) {
    int row = stones[i][0], col = stones[i][1];

    connect(rowMap[row], i, par, size);
    connect(colMap[col], i, par, size);
  }

  // Compress all uncompressed edges
  for (int i = 0; i < stoneCount; i++) find(i, par);

  unordered_set<int> comps;

  for (int i = 0; i < stoneCount; i++) comps.insert(par[i]);

  int removeCount = 0;
  for (int i : comps) {
    int stoneCountInComp = 0;
    for (int j = 0; j < stoneCount; j++) {
      if (par[j] == i) stoneCountInComp++;
    }
    removeCount += stoneCountInComp - 1;
  }

  return removeCount;
}

int main() { return 0; }