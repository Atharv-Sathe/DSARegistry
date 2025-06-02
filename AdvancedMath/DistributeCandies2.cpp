#include <iostream>
using namespace std;

// This function simply returns number of ways to select b positions out of a
long long binomial(int a, int b) {
  long long num, deno;
  for (int i = 0; i < b; i++) {
    num *= a - i;
    deno *= b - i;
  }
  return num / deno;
}

/*
Logic : 
let Total = Number of ways to distribute n candies among 3 childs
let Ans = Number of ways to distribute n candies among 3 childs such that each gets at most limit
let A = Number of ways to distribute n candies such that child 1 receives at least limit + 1
let B = Number of ways to distribute n candies such that child 1 receives at least limit + 1
let C = Number of ways to distribute n candies such that child 1 receives at least limit + 1

Ans = Total - |A U B U C| + |A Inter B| + |B Inter C| + |A Inter C| - |A Inter B Inter C|

*/

int getNumberOfDistributions(int n, int limit) {
  // Inorder to divide n into three parts we need to create 2 divides
  // In other words I need to choose 2 positions out 7 posible positions
  int total = binomial(n + 2, 2);

  // In order to find out A, I have already assigned limit + 1 candies to A and 
  // and then I am distributing the rest freely among the three
  int A = binomial(n - (limit + 1) + 2, 2);

  int A2 = binomial(n - 2 * (limit + 1) + 2, 2);

  int A3 = binomial(n - 3 * (limit + 1) + 2, 2);

  return total - 3 * A + 3 * A2 - A3;
}

int main() {
  int n = 5, limit = 2;

  cout << getNumberOfDistributions(n, limit) << endl;
  
  return 0;
}