#include <iostream>
#include <vector>
using namespace std;

/*
There are n children standing in a line. Each child is assigned a 
rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the 
candies to the children.
*/

int candy(vector<int>& ratings) {
  int n = ratings.size();
  vector<int> candies(n, 0);
  for (int i = 0; i < n; i++) {
      // Check right
      if (i != n - 1 && ratings[i] > ratings[i + 1]) {
          candies[i] = 1;
      } 

      // Check left
      if (i != 0 && ratings[i] > ratings[i - 1]) {
          candies[i] = max(candies[i], candies[i - 1] + 1);
      }

  }
  int total = 0;
  for (int i = n - 1; i >= 0; i--) {
      // Check right
      if (i != n - 1 && ratings[i] > ratings[i + 1]) {
          candies[i] = candies[i + 1] + 1;
      } 

      // Check left
      if (i != 0 && ratings[i] > ratings[i - 1]) {
          candies[i] = max(candies[i], candies[i - 1] + 1);
      }
      total += candies[i];
  }

  // int total = accumulate(begin(candies), end(candies), 0);
  return total + n;
}

int main() {
  
  return 0;
}