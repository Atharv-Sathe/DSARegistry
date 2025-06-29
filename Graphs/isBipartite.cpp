#include <iostream>
#include <vector>
using namespace std;

/*
There is an undirected graph with n nodes, where each node is numbered 
between 0 and n - 1. You are given a 2D array graph, where graph[u] is 
an array of nodes that node u is adjacent to. More formally, for each 
v in graph[u], there is an undirected edge between node u and node v. 
The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such 
that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets 
A and B such that every edge in the graph connects a node in set A and a node 
in set B.

Return true if and only if it is bipartite.

*/


bool dfs(vector<vector<int>>& adj, int i, vector<bool>& visited, bool col,
         vector<bool>& colors) {
  visited[i] = true;
  colors[i] = col;

  for (int nbr : adj[i]) {
    if (visited[nbr] && colors[nbr] == col) return false;

    if (!visited[nbr]) {
      if (!dfs(adj, nbr, visited, !col, colors)) return false;
    }
  }

  return true;
}

bool isBipartite(vector<vector<int>>& graph) {
  int m = graph.size();
  vector<bool> visited(m, false);
  vector<bool> colors(m, false);

  for (int i = 0; i < m; i++) {
    if (!visited[i]) {
      if (!dfs(graph, i, visited, 0, colors)) {
        return false;
      }
    }
  }
  return true;
}

int main() { return 0; }