#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

/*
    Given a list of accounts where each element accounts[i] is a list of strings, 
    where the first element accounts[i][0] is a name, and the rest of the elements 
    are emails representing emails of the account.

    Now, we would like to merge these accounts. Two accounts definitely belong to the 
    same person if there is some common email to both accounts. Note that even if two 
    accounts have the same name, they may belong to different people as people could 
    have the same name. A person can have any number of accounts initially, but all 
    of their accounts definitely have the same name.

    After merging the accounts, return the accounts in the following format: the first 
    element of each account is the name, and the rest of the elements are emails in 
    sorted order. The accounts themselves can be returned in any order.
*/

int find(int n, vector<int>& par) {
  int root = n;
  while (root != par[root]) {
    root = par[root];
  }

  while (n != par[root]) {
    int next = par[n];
    par[n] = root;
    n = next;
  }

  return root;
}

void connect(int a, int b, vector<int>& par, vector<int>& size) {
  int root1 = find(a, par);
  int root2 = find(b, par);

  if (root1 == root2) return;

  if (size[root1] < size[root2]) {
    size[root2] += size[root1];
    par[root1] = root2;
  } else {
    size[root1] += size[root2];
    par[root2] = root1;
  }
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
  // Each email is a node
  unordered_map<string, string> emailToName;
  unordered_map<string, int> emailToId;
  int id = 0;

  // Assign Ids to all emails
  for (auto& account : accounts) {
    for (int emailInd = 1; emailInd < account.size(); emailInd++) {
      if (!emailToId.count(account[emailInd]))
        emailToId[account[emailInd]] = id++;
      emailToName[account[emailInd]] = account[0];
    }
  }

  // Connect all emails
  vector<int> par(id);
  iota(par.begin(), par.end(), 0);
  vector<int> size(id, 1);

  for (auto& account : accounts) {
    for (int emailInd = 1; emailInd < account.size() - 1; emailInd++) {
      connect(emailToId[account[emailInd]], emailToId[account[emailInd + 1]],
              par, size);
    }
  }

  vector<vector<string>> result;

  // Build groups of emails
  unordered_map<int, set<string>> rootToEmails;
  for (const auto& [email, emailId] : emailToId) {
    int rootId = find(emailId, par);
    rootToEmails[rootId].insert(email);
  }

  // Construct the result
  for (const auto& [id, emailList] : rootToEmails) {
    vector<string> temp{emailToName[*emailList.begin()]};
    temp.insert(temp.end(), emailList.begin(), emailList.end());
    result.push_back(temp);
  }

  return result;
}

int main() { return 0; }