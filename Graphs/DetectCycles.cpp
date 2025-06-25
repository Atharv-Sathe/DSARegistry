#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
  Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], 
  where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether 
  the graph contains a cycle or not.
*/

bool bfs(vector<vector<int>>& adj, vector<bool>& visited, int start) {
  // stores the node and its immediate parent
  queue<pair<int, int>> q;
  q.push({start, -1});
  visited[start] = true;

  while (!q.empty()) {
    int node = q.front().first;
    int immediateParent = q.front().second;
    q.pop();

    for (auto neighbour : adj[node]) {
      if ((neighbour != immediateParent) && visited[neighbour]) return true;

      if (!visited[neighbour]) {
        q.push({neighbour, node});
        visited[neighbour] = true;
      }
    }
  }

  return false;
}

bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int ind, int parent) {
  visited[ind] = true;

  for (int nbr : adj[ind]) {
    if ((nbr != parent) && visited[nbr]) return true;

    if (!visited[nbr]) {
      if (dfs(adj, visited, nbr, ind)) return true;
    }
  }

  return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
  // BFS
  vector<vector<int>> adj(V);

  for (auto& edge : edges) {
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
  }

  vector<bool> visited(V, false);

  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      // if (bfs(adj, visited, i)) {
      //     return true;
      // }

      if (dfs(adj, visited, i, -1)) return true;
    }
  }

  return false;
}

int main() { return 0; }