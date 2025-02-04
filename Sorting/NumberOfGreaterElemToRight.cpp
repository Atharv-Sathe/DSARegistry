#include <iostream>
#include <vector>
#define FLOOP(a, b) for (int i = a; i < b; i++)
using namespace std;

/*
Given an array of N integers and Q queries of indices. 
For each query indices[i], determine the count of elements 
in arr that are strictly greater than arr[indices[i]] to its 
right (after the position indices[i]).
*/

void merge(vector<pair<int, int>>& vec, vector<int>& ans, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    
    vector<pair<int, int>> arr, brr;
    
    FLOOP(0, n1) {
        arr.push_back(vec[low + i]);
    }
    
    FLOOP(0, n2) {
        brr.push_back(vec[i + mid + 1]);
    }
    
    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2) {
        if (arr[i].first < brr[j].first) {
            ans[arr[i].second] += n2 - j;
            vec[k] = arr[i];
            i++;
        } else {
            vec[k] = brr[j];
            j++;
        }
        k++;
    }
    
    
    while (i < n1) {
        vec[k] = arr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        vec[k] = brr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<pair<int, int>>& vec, vector<int>& ans, int low, int high) {
    int mid;
    if (low < high) {
        mid = low + (high - low) / 2;
        
        mergeSort(vec, ans, low, mid);
        mergeSort(vec, ans, mid + 1, high);
        
        merge(vec, ans, low, mid, high);
    }
}

vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
    vector<pair<int,int>> vec;
    FLOOP(0, arr.size()) {
        vec.push_back({arr[i], i});
    }
    vector<int> ans(n, 0);
    mergeSort(vec, ans, 0, n - 1);
    vector<int> res;
    FLOOP(0, queries) {
        res.push_back(ans[indices[i]]);
    }
    return res;
    
}

int main() {
    
    return 0;
}
