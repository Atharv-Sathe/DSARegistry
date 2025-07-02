#include <bits/stdc++.h>
using namespace std;

/*
There is a directed graph of n nodes with each node labeled from 0 to n - 1.
The graph is represented by a 0-indexed 2D integer array graph where graph[i]
is an integer array of nodes adjacent to node i, meaning there is an edge from
node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node
if every possible path starting from that node leads to a terminal node
(or another safe node).

Return an array containing all the safe nodes of the graph. The answer
should be sorted in ascending order.

Logic:
- The problem is solved using a variation of Kahn's Algorithm (topological sort).
- First, reverse all edges in the graph. For each edge u -> v in the original graph, add v -> u in the reversed graph.
- Compute the indegree for each node in the reversed graph (i.e., count of incoming edges).
- All terminal nodes in the original graph will have indegree 0 in the reversed graph.
- Use a queue to process all nodes with indegree 0 (these are terminal nodes and hence safe).
- For each node removed from the queue, reduce the indegree of its neighbors in the reversed graph.
- If any neighbor's indegree becomes 0, add it to the queue (it is now safe).
- Continue until the queue is empty.
- All nodes marked as safe are those from which every path leads to a terminal node.
- Return the sorted list of safe nodes.
*/

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
  // Apply Kahn's Algo after reversing the edges
  int nodeCount = graph.size();
  vector<vector<int>> adjList(nodeCount);
  vector<int> indegree(nodeCount, 0);

  // Reverse the edges and compute indegrees
  for (int i = 0; i < nodeCount; i++) {
    for (int j : graph[i]) {
      adjList[j].push_back(i); // reverse edge
      indegree[i]++;           // count outgoing edges for original node
    }
  }

  vector<bool> safeNodes(nodeCount, false);
  safeNodes.reserve(nodeCount);
  queue<int> q;

  // All nodes with indegree 0 are terminal nodes (safe)
  for (int i = 0; i < nodeCount; i++)
    if (indegree[i] == 0) q.push(i);

  // Process nodes with indegree 0 and propagate safety
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    safeNodes[node] = true;

    for (int nbr : adjList[node]) {
      indegree[nbr]--;
      if (indegree[nbr] == 0) q.push(nbr);
    }
  }

  // Collect all safe nodes
  vector<int> result;
  for (int i = 0; i < nodeCount; i++)
    if (safeNodes[i]) result.push_back(i);
  return result;
}

int main() { return 0; }