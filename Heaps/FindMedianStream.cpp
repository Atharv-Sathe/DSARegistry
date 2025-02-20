#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Given a data stream arr[] where integers are read sequentially, the task is to 
determine the median of the elements encountered so far after each new integer is read.

There are two cases for median on the basis of data set size.

1. If the data set has an odd number then the middle one will be consider as median.
2. If the data set has an even number then there is no distinct middle value and the median will be the arithmetic mean of the two middle values.
*/


bool isOdd(int a, int b) {
    return (a + b) & 1;
}

vector<double> getMedian(vector<int> &arr) {
    priority_queue<int> leftPq;
    priority_queue<int, vector<int>, greater<int>> rightPq;
    vector<double> answer;
    
    for (int i = 0; i< arr.size(); i++) {
        if (leftPq.empty() || arr[i] <= leftPq.top()) leftPq.push(arr[i]);
        else rightPq.push(arr[i]);
        
        int l = leftPq.size(), r = rightPq.size();
        if (l - r > 1) {
            rightPq.push(leftPq.top()); leftPq.pop();
        } else if (r - l > 1) {
            leftPq.push(rightPq.top()); rightPq.pop();
        }
        
        if (isOdd(l, r)) {
            answer.push_back((leftPq.size() > rightPq.size()) ? leftPq.top() : rightPq.top());
        } else {
            answer.push_back((leftPq.top() + rightPq.top()) / 2.0);
        }
    }
    return answer;
}

int main() {
  
  return 0;
}