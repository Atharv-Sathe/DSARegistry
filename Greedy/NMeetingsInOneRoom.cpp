#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
You are given timings of n meetings in the form of (start[i], end[i]) 
where start[i] is the start time of meeting i and end[i] is the finish 
time of meeting i. Return the maximum number of meetings that can be 
accommodated in a single meeting room, when only one meeting can be held 
in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time 
of the other chosen meeting.
*/

int maxMeetings(vector<int>& start, vector<int>& end) {
    // Soring according to least ending time first
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    
    for (int i = 0; i < start.size(); i++) {
        pq.push({end[i], start[i]});
    }
    int meetCount = 1;
    
    // auto [curStart, curEnd] = pq.top();
    int curStart = pq.top().second;
    int curEnd = pq.top().first;
    pq.pop();
    while(!pq.empty()) {
        if (pq.top().second > curEnd) {
            meetCount++;
            curEnd = pq.top().first;
        }
        pq.pop();
    }
    return meetCount;
}

int main() {
  
  return 0;
}