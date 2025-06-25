#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Given a connected undirected graph containing V vertices, represented by a 2-d
adjacency list adj[][], where each adj[i] represents the list of vertices
connected to vertex i. Perform a Breadth First Search (BFS) traversal starting
from vertex 0, visiting vertices from left to right according to the given
adjacency list, and return a list containing the BFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list.
*/

// Function to return Breadth First Traversal of given graph.
vector<int> bfs(vector<vector<int>> &adj) {
  vector<int> result;
  queue<int> q;
  unordered_set<int> visited;

  q.push(0);
  visited.insert(0);

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    result.push_back(node);

    for (int n : adj[node]) {
      if (!visited.count(n)) {
        visited.insert(n);
        q.push(n);
      }
    }
  }

  return result;
}

int main() { return 0; }