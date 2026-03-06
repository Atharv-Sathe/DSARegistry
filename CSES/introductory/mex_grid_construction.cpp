#include<iostream>
#include<vector>
using namespace std;

// Max num in grid = 2n - 3

// Brute Force
void solve(vector<vector<int>>& grid) {
  int n = grid.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k <= 2*n - 3; k++) {
        bool isValid = true;
        // Left Check
        for (int l = 0; l < j; l++) {
          if (grid[i][l] == k) {
            isValid = false;
            break;
          }
        }
        
        // Up Check
        if (isValid) {
          for (int u = 0; u < i; u++) {
            if (grid[u][j] == k) {
              isValid = false;
              break;
            }
          }
        }

        if (isValid) {
          grid[i][j] = k;
          break;
        }
      }
    }
  }
}


int main() {
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n,0));
  solve(grid);
  for (auto& row : grid) {
    for (int i : row) {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}
