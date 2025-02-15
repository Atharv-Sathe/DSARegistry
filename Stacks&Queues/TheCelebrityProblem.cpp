#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find if there is a celebrity in the party or not.
int celebrity(vector<vector<int> >& mat) {
    // Iterate over each column O(n^2)
    // int cols = mat[0].size();
    // int rows = mat.size();
    // int cR = -1;
    // for (int i = 0 ; i < cols; i++) {
    //     int r = -1;
    //     int sum = 0;
    //     for (int j = 0; j < rows; j++) {
    //         sum += mat[j][i];
    //         if (!mat[j][i]) r = j; // Stores most recent zero index;
    //     }
    //     if (sum == cols - 1) cR = r;
    // }
    
    // // Check if celebrite knows no one
    // if (cR != -1) {
    //     for (int i: mat[cR]) {
    //         if (i) return -1;
    //     }
    // }
    // return cR;
    
    
    // Check if celeb
    stack<int> s;
    for (int i = 0; i < mat.size(); i++) s.push(i);
    
    while(s.size() > 1) {
        int A = s.top(); s.pop();
        int B = s.top(); s.pop();
        if (mat[A][B]) s.push(B); // A knows B
        else if (mat[B][A]) s.push(A); // B knows A;
    }
    
    // Potential Candidate
    int P = s.top();
    s.pop();
    
    // Check if P is celeb
    for (int i = 0; i < mat.size(); i++) {
        if ((i != P) && (!mat[i][P] || mat[P][i])) return -1;
    }
    return P;
}

int main() {
    
    return 0;
}