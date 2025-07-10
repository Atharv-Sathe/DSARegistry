#include <bits/stdc++.h>
using namespace std;

/*
  Given an undirected connected graph with V vertices and adjacency list adj. 
  You are required to find all the vertices removing which (and edges through it) 
  disconnects the graph into 2 or more components and return it in sorted manner.
  Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be 
  loops present in the graph.
*/

// User function Template for C++

void dfs(vector<int> adj[], int node, vector<bool>& visited, vector<int>& disc,
         vector<int>& low, int parent, set<int>& result, int& time) {
  visited[node] = true;
  disc[node] = low[node] = time++;
  int child = 0;
  for (int nbr : adj[node]) {
    if (nbr == parent) continue;

    if (!visited[nbr]) {
      dfs(adj, nbr, visited, disc, low, node, result, time);
      low[node] = min(low[node], low[nbr]);

      // Check if this is an articulation point
      if (low[nbr] >= disc[node] && parent != -1) {
        result.insert(node);
      }
      child++;
    } else {
      low[node] = min(low[node], disc[nbr]);
    }
  }

  if (parent == -1 && child > 1) result.insert(node);
}

vector<int> articulationPoints(int V, vector<int> adj[]) {
  // Data structures
  vector<bool> visited(V, false);
  vector<int> disc(V, -1);
  vector<int> low(V, -1);
  int parent = -1;

  set<int> result;
  int time = 0;
  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      dfs(adj, i, visited, disc, low, parent, result, time);
    }
  }

  vector<int> res(result.begin(), result.end());

  if (res.size()) {
    return res;
  }
  return {-1};
}

int main() { return 0; }