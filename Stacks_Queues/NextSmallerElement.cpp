#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    vector<int> answer(A.size(), -1);
    stack<int> incMonSt;
    for (int i = 0; i < A.size(); i++) {
        while(!incMonSt.empty() && incMonSt.top() >= A[i]) incMonSt.pop();
        if (!incMonSt.empty()) answer[i] = incMonSt.top();
        incMonSt.push(A[i]);
    }
    return answer;
}

int main() {
    
    return 0;
}