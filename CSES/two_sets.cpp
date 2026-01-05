#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

// Backtraking O(2^N)
bool helper(int n, int i, long long runningSum, unordered_set<int>& selected) {
  if (runningSum == 0) {
    return true;
  }

  if (i > n) {
    return false;
  }

  if (runningSum >= i) {
    selected.insert(i);
    if (helper(n, i + 1, runningSum - i, selected)) {
      return true;
    }
    selected.erase(i);
  }

  return helper(n, i + 1, runningSum, selected);
}

void solve(int n) {
  long long sum = 1ll * n * (n + 1) / 2;
  if (sum & 1) {
    cout << "NO";
    return;
  }
  
  unordered_set<int> selected;
  if (helper(n, 1, sum / 2, selected)) {
      cout << "YES\n";
      cout << selected.size() << "\n";
      for (int i : selected) {
        cout << i << " ";
      }
      cout << "\n" <<  n - selected.size() << "\n";
      for (int i = 1; i <= n; i++) {
        if (!selected.count(i)) {
          cout << i << " ";
        }
      }
  } else {
    cout << "NO";
  }
  return;
}

// O(N)
void solve2(int n) {
  long long sum = 1ll * n * (n + 1) / 2;
  if (sum & 1) {
    cout << "NO";
    return;
  }

  vector<int> A, B;
  long long sumA = 0, sumB = 0;
  for (int i = n; i > 0; i--) {
    if (sumA <= sumB) {
      A.push_back(i);
      sumA += i;
    } else {
      B.push_back(i);
      sumB += i;
    }
  }

  if (sumA == sumB) {
    cout << "YES\n";
    cout << A.size() << "\n";
    for (int i : A) {
      cout << i << " ";
    }
    cout << "\n" << B.size() << "\n";
    for (int i : B) {
      cout << i << " ";
    }
  } else {
    cout << "NO";
  }
  return;
}

int main() {
  int n; 
  cin >> n;
  // solve(n);
  solve2(n);
  return 0;
}
