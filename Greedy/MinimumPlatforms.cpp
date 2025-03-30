#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
You are given the arrival times arr[] and departure times dep[] of all trains that arrive 
at a railway station on the same day. Your task is to determine the minimum number of platforms 
required at the station to ensure that no train is kept waiting.

At any given time, the same platform cannot be used for both the arrival of one train and the 
departure of another. Therefore, when two trains arrive at the same time, or when one arrives 
before another departs, additional platforms are required to accommodate both trains.

*/

int findPlatform(vector<int>& arr, vector<int>& dep) {
  vector<int> platforms;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int i = 0; i < arr.size(); i++) {
      // pq.push({dep[i], arr[i]});
      pq.push({arr[i], dep[i]});
  }
  
  while(!pq.empty()) {
      // int curTrainDep = pq.top().first;
      // int curTrainArr = pq.top().second;
      int curTrainDep = pq.top().second;
      int curTrainArr = pq.top().first;
      pq.pop();
      // Find if a station is empty
      int i = 0;
      for (; i < platforms.size(); i++) {
          if (platforms[i] < curTrainArr) {
              platforms[i] = curTrainDep;
              break;
          }
      }
      
      // If i reaches the end of platforms, this suggests no platform free...
      if (i == platforms.size()) platforms.push_back(curTrainDep);
  }
  return platforms.size();
}

int main() {
  
  return 0;
}