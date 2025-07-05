#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
  // Build Graph
  int mod = 1e9 + 7;

  vector<vector<pair<int, int>>> adjList(n);
  for (auto& road : roads) {
    adjList[road[0]].push_back({road[1], road[2]});
    adjList[road[1]].push_back({road[0], road[2]});
  }

  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      pq;
  pq.push({0, 0});

  vector<long long> ways(n, 0);
  ways[0] = 1;

  vector<long long> distances(n, LLONG_MAX);
  distances[0] = 0;

  while (!pq.empty()) {
    auto [dist, node] = pq.top();
    pq.pop();


    /*
      NOTE : Most AI's will tell you to remove this early termination, however
      if you know how dijkstra actually works then you would realize that this optimization
      is actually safe and doesn't change the final result.
      You see once we pop the target node for the first time, we have already found the
      definitive shortest path and have already taken into account all the paths through
      other links which would have lead us to the target node in the shortest path.
      Even if there are some unprocessed nodes in the PQ which also lead to the target 
      node, still they are inconsequential to us cause they will surely be costlier.
    */

    // Early Termination
    if (node == n - 1) return ways[node] % mod;

    // Minor Optimization
    if (distances[node] < dist) continue;

    for (auto& nbr : adjList[node]) {
      auto [intersection, time] = nbr;
      long long newTime = distances[node] + time;
      if (newTime < distances[intersection]) {
        distances[intersection] = newTime;
        ways[intersection] = ways[node];
        pq.push({newTime, intersection});
      } else if (newTime == distances[intersection]) {
        ways[intersection] = (ways[intersection] + ways[node]) % mod;
      }
    }
  }

  return ways[n - 1];
}

int main() { return 0; }