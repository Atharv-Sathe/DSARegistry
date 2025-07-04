#include <iostream>
#include <vector>
using namespace std;

/*
Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, 
represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes an 
edge between vertices u and v.

Your task is to return a list of all connected components. Each connected component 
should be represented as a list of its vertices, with all components returned in a 
collection where each component is listed separately.

Note: You can return the components in any order, driver code will print the components 
in sorted order.
*/

void dfs(int i, vector<vector<int>> &adjList, vector<int> &used,
         vector<int> &components) {
  used[i] = true;
  components.push_back(i);

  for (auto neighbour : adjList[i]) {
    if (!used[neighbour]) {
      dfs(neighbour, adjList, used, components);
    }
  }
}

// TC : (V + E)
vector<vector<int>> getComponents(int V, vector<vector<int>> &edges) {
  vector<vector<int>> adjList(V);

  // Creating an adjacency list
  for (auto &edge : edges) {
    adjList[edge[0]].push_back(edge[1]);
    adjList[edge[1]].push_back(edge[0]);
  }

  vector<int> used(V, false);

  vector<vector<int>> results;
  // For every vertex doing dfs
  for (int i = 0; i < V; i++) {
    if (!used[i]) {
      vector<int> components;
      dfs(i, adjList, used, components);
      results.push_back(components);
    }
  }

  return results;
}

int main() { return 0; }