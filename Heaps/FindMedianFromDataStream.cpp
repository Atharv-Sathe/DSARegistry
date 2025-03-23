#include <iostream>
#include <queue>
using namespace std;

/*
The median is the middle value in an ordered integer list. If the size of 
the list is even, there is no middle value, and the median is the mean of 
the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 
10-5 of the actual answer will be accepted.

*/

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

void addNum(int num) {
  // pq.push(num);

  // if (maxHeap.empty() || maxHeap.top() >= num) maxHeap.push(num);
  // else if (minHeap.empty() || minHeap.top() <= num) minHeap.push(num);

  // if (maxHeap.size() - minHeap.size() > 1) {
  //     minHeap.push(maxHeap.top()); maxHeap.pop();
  // } else if (minHeap.size() - maxHeap.size() > 1) {
  //     maxHeap.push(minHeap.top()); minHeap.pop();
  // }

  maxHeap.push(num);

  if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
  } 

  if (maxHeap.size() > minHeap.size() + 1) minHeap.push(maxHeap.top()), maxHeap.pop();
  if (minHeap.size() > maxHeap.size() + 1) maxHeap.push(minHeap.top()), minHeap.pop();
  
}

double findMedian() {
  // Brute
  // auto pqCopy = pq;
  // double answer;
  // int n = pqCopy.size();
  // if (n & 1) {
  //     for (int i = 0; i < n / 2; i++) pqCopy.pop();
  //     answer = (double)pqCopy.top();
  // } else {
  //     for (int i = 0; i < (n / 2) - 1; i++) pqCopy.pop();
  //     double n1 = pqCopy.top(); pqCopy.pop();
  //     double n2 = pqCopy.top();
  //     answer = (n1 + n2) / 2;
  // }
  // return answer;

  double answer;
  if (maxHeap.size() == minHeap.size()) {
      answer = (double)(maxHeap.top() + minHeap.top()) / 2;
  } else answer = (maxHeap.size() > minHeap.size()) ? maxHeap.top() : minHeap.top();

  return answer;
}

int main() {
  
  return 0;
}