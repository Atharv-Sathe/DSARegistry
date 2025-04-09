#include <iostream>
#include <vector>
using namespace std;

/*
Geek is going for a training program for n days. He can perform any of these activities: 
Running, Fighting, and Learning Practice. Each activity has some point on each day. As 
Geek wants to improve all his skills, he can't do the same activity on two consecutive days. 
Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] represent the 
merit points for Running, Fighting, and Learning on the i-th day, determine the maximum 
total merit points Geek can achieve .
*/

int recurseNaive(vector<vector<int>>& arr, int day, int prev) {
  if (day == arr.size()) {
      return 0;
  }
  
  int maxMerit = INT_MIN;
  for (int i = 0; i < 3; i++) {
      if (i == prev) continue;
      maxMerit = max(maxMerit, arr[day][i] + recurseNaive(arr, day + 1, i));
  }
  return maxMerit;
}


// Memo + Bottom Up
int dpBottomUp(vector<vector<int>>& arr, vector<vector<int>>& memo, int day, int prev) {
  if (day == arr.size()) {
      return 0;
  }
  if (memo[day][prev + 1] != -1) return memo[day][prev + 1];
  
  
  int maxMerit = INT_MIN;
  for (int i = 0; i < 3; i++) {
      if (i == prev) continue;
      maxMerit = max(maxMerit, arr[day][i] + dpBottomUp(arr, memo, day + 1, i));
  }
  
  memo[day][prev + 1] = maxMerit;
  
  return maxMerit;
}

// Memo + Top Down + Space Op 
int dpTopDownSpaceOp(vector<vector<int>>& arr) {
  int d = arr.size();
  vector<vector<int>> memo(d + 1, vector<int>(4, 0));
  
  for (int day = d - 1; day >= 0; day--) {
      for (int prev = 0; prev < 4; prev++) {
          int maxPoints = INT_MIN;
          for (int task = 0; task < 3; task++) {
              if (task == prev) continue;
              maxPoints = max(maxPoints, arr[day][task] + memo[day + 1][task]);
          }
          memo[day][prev] = maxPoints;
      }
  }
  return memo[0][3];
}

int main() {
  
  return 0;
}