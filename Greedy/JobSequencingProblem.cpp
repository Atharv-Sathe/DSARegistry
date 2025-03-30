#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
You are given two arrays: deadline[], and profit[], which represent a set of jobs, 
where each job is associated with a deadline, and a profit. Each job takes 1 unit of 
time to complete, and only one job can be scheduled at a time. You will earn the profit 
associated with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.
*/

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
  // Brute Force
  // int n = profit.size();
  // vector<pair<int, int>> jobs;
  // for (int i = 0; i < n; i++) {
  //     jobs.push_back({profit[i], deadline[i]});
  // }
  
  // sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());
  
  // vector<int> slot(n, 0);
  // int jobCount = 0, maxProf = 0;
  // for (int i =0; i < n; i++) {
  //     int start = min(n, jobs[i].second) - 1;
  //     for (int j = start; j >= 0; j--) {
  //         if (!slot[j]) {
  //             slot[j] = 1;
  //             jobCount++, maxProf += jobs[i].first;
  //             break;
  //         }
  //     }
  // }
  
  // return {jobCount, maxProf};
  
  // Optimized
  int n = profit.size();
  vector<pair<int, int>> jobs;
  for (int i = 0; i < n; i++) {
      jobs.push_back({deadline[i], profit[i]});
  }
  
  sort(jobs.begin(), jobs.end());
  
  priority_queue<int, vector<int>, greater<int>> pq;
  
  for (const auto& job: jobs) {
      if (job.first > pq.size()) {
          pq.push(job.second);
      } else if (!pq.empty() && pq.top() < job.second) {
          pq.pop();
          pq.push(job.second);
      }
  }
  
  int jobCount = pq.size();
  int totalProf = 0;
  while(!pq.empty()) {
      totalProf += pq.top();
      pq.pop();
  }
  return {jobCount, totalProf};
}

int main() {
  
  return 0;
}