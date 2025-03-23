#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

/*
Given two integer array A and B of size N each.
A sum combination is made by adding one element from array A and another element of array B.
Return the maximum K valid sum combinations from all the possible sum combinations.

Note : Output array must be sorted in non-increasing order.
*/

vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
  sort(rbegin(A), rend(A));
  sort(rbegin(B), rend(B));
  
  priority_queue<pair<int, pair<int, int>>> pq;
  set<pair<int, int>> used;
  
  pq.push({A[0] + B[0], {0, 0}}), used.insert({0, 0});
  vector<int> topK;
  
  while(topK.size() < K) {
      auto top = pq.top();
      pq.pop();
      int sum = top.first;
      // auto [i, j] = top.second;
      int i = top.second.first;
      int j = top.second.second;
      
      topK.push_back(sum);
      
      if (i + 1 < N && !used.count({i + 1, j})) {
          pq.push({A[i + 1] + B[j], {i + 1, j}});
          used.insert({i + 1, j});
      }
      
      if (j + 1 < N && !used.count({i, j + 1})) {
          pq.push({A[i] + B[j + 1], {i, j + 1}});
          used.insert({i, j + 1});
      }
  }
  
  return topK;
}

int main() {
  
  return 0;
}