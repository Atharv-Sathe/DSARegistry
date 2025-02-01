#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
You are given a two-dimensional mat[][] of size n*m containing English 
alphabets and a string word. Check if the word exists on the mat. The 
word can be constructed by using letters from adjacent cells, 
either horizontally or vertically. The same cell cannot be used more than once.
*/


int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool backtrack(vector<vector<char>>& mat, int r, int c, string& word, int idx, vector<vector<bool>>& visited) {
    if (idx == word.length()) {
        return true;
    }
    
    if (r < 0 || r >= mat.size() || c < 0 || c >= mat[0].size() ||
        visited[r][c] || mat[r][c] != word[idx]) {
            return false;
        }
    
    visited[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int newR = r + dx[i];
        int newC = c + dy[i];
        
        if (backtrack(mat, newR, newC, word, idx + 1, visited)) {
            return true;
        }
    }
    visited[r][c] = false;
    return false;
    
}

bool isWordExist(vector<vector<char>>& mat, string& word) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == word[0] && backtrack(mat, i, j, word, 0, visited)) return true;
        }
    }
    return false;
}

int main() {
    
    return 0;
}