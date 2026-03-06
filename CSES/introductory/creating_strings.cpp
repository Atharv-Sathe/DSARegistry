#include<iostream>
#include<set>
#include<string>
using namespace std;

void solve(string& s, int itr, string& str, set<string>& perms) {
  int n = s.size();
  if (itr == n) {
    perms.insert(str);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      continue;
    }
    char temp = s[i];
    str += temp;
    s[i] = '0';
    solve(s, itr + 1, str, perms);
    s[i] = temp;
    str.pop_back();
  }
  return;
}

int main() {
  string s;
  cin >> s;
  set<string> perms;
  string str = "";
  solve(s, 0, str, perms);
  cout << perms.size() << "\n";
  for (const string& str: perms) {
    cout << str << "\n";
  }
  return 0;
}
