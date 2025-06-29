#include <iostream>
#include <vector>
using namespace std;

/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check 
whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry 
edges[i] = [u, v] denotes an edge from verticex u to v.
*/

bool dfs(vector<vector<int>>& adj, int i, vector<bool>& visited,
         vector<bool>& recStack) {
  // If a node is in the recursion stack, it means we have a cycle
  if (recStack[i]) return true;

  // If a node is not in recursion stack but has been visited, no need check
  // again
  if (visited[i]) return false;

  visited[i] = true;
  recStack[i] = true;

  for (int nbr : adj[i]) {
    if (dfs(adj, nbr, visited, recStack)) return true;
  }

  // Remove the current node from recursive stack
  recStack[i] = false;

  return false;
}

bool isCyclic(int V, vector<vector<int>>& edges) {
  // Creating an adj list
  vector<vector<int>> adj(V);

  for (auto& edge : edges) {
    adj[edge[0]].push_back(edge[1]);
  }

  vector<bool> visited(V, false);
  vector<bool> recStack(V, false);
  for (int i = 0; i < V; i++) {
    if (!visited[i] && dfs(adj, i, visited, recStack)) {
      return true;
    }
  }

  return false;
}

int main() { return 0; }