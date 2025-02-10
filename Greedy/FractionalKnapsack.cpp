#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
Given two arrays, val[] and wt[], representing the values and weights of 
items, and an integer capacity representing the maximum weight a knapsack 
can hold, determine the maximum total value that can be achieved by putting 
items in the knapsack. You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.
*/

// Function to get the maximum total value in the knapsack.
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    vector<pair<int,int>> valWt;
    for (int i = 0; i < val.size(); i++) {
        valWt.push_back({val[i], wt[i]});
    }
    
    sort(valWt.begin(), valWt.end(), [](auto& p1, auto& p2) {
        return ((double)p1.first / p1.second) > ((double)p2.first / p2.second);
    });
    
    double profit = 0;
    for (const auto& p : valWt) {
        if (p.second <= capacity) {
            profit += p.first;
            capacity -= p.second;
        } else {
            profit += ((double)p.first / p.second) * capacity;
            capacity = 0;
        }
    }
    return profit;
}

int main() {
    
    return 0;
}