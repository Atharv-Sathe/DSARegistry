#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void recursiveDFS(vector<vector<int>>& adj, vector<int>& visited,
                  vector<int>& result, int n) {
  visited[n] = true;
  result.push_back(n);

  for (int i : adj[n]) {
    if (!visited[i]) {
      recursiveDFS(adj, visited, result, i);
    }
  }
}


/*  
  It is important to note that, we must mark a node as visited only when 
  we are pushing it to the results array and not when we are pushing it to 
  stack, this is in order to maintain the DFS order..
  This is not required in BFS becuase, once we add something in the queue
  then its order is determined and won't be changed.
*/
vector<int> iterativeDFS(vector<vector<int>>& adj) {
  int n = adj.size();  // Use int instead of size_t
  stack<int> st;
  vector<bool> visited(n, false);  // vector<bool> is more appropriate

  st.push(0);

  vector<int> result;

  while (!st.empty()) {
    int node = st.top();
    st.pop();

    if (visited[node]) continue;

    visited[node] = true;
    result.push_back(node);

    // Clearer iteration through neighbors
    for (int i = adj[node].size() - 1; i >= 0; i--) {
      int neighbor = adj[node][i];
      if (!visited[neighbor]) {
        st.push(neighbor);
      }
    }
  }

  return result;
}

vector<int> dfs(vector<vector<int>>& adj) {
  // Code here
  // size_t t = adj.size();
  // vector<int> visited(t, false);
  // vector<int> result;

  // recursiveDFS(adj, visited, result, 0);
  // return result;

  return iterativeDFS(adj);
}

int main() { return 0; }