#include <bits/stdc++.h>
using namespace std;

/*
  There are n cities connected by some number of flights. You are given an array 
  flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

  You are also given three integers src, dst, and k, return the cheapest price from 
  src to dst with at most k stops. If there is no such route, return -1.

*/

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                      int k) {
  vector<vector<pair<int, int>>> adjList(n);
  for (auto& flight : flights) {
    adjList[flight[0]].push_back({flight[1], flight[2]});
  }

  queue<vector<int>> pq;
  pq.push({0, src, 0});

  vector<int> dist(n, INT_MAX);
  dist[src] = 0;
  while (!pq.empty()) {
    int cost = pq.front()[0], city = pq.front()[1], stops = pq.front()[2];
    pq.pop();

    for (auto& node : adjList[city]) {
      if (stops == k && node.first != dst) continue;

      int newCost = cost + node.second;
      if (newCost < dist[node.first]) {
        dist[node.first] = newCost;
        pq.push({newCost, node.first, stops + 1});
      }
    }
  }
  return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main() { return 0; }