#include <bits/stdc++.h>
using namespace std;

bool canPlaceStations(vector<int>& stations, int k, double maxDist) {
    int stationsPlaced = 0;
    for (int i = 1; i < stations.size(); i++) {
        int diff = stations[i] - stations[i - 1];
        stationsPlaced += ceil(diff/maxDist) - 1;
        if (stationsPlaced > k) return false;
    }
    return true;
}

double findSmallestMaxDist(vector<int> &stations, int k) {
    double left = 0, right = stations.back() - stations[0];
    while(right - left > 1e-6) {
        double mid = (left + right) / 2;
        if (canPlaceStations(stations, k, mid)) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    
    return 0;
}
