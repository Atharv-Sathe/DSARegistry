#include <bits/stdc++.h>
using namespace std;

long long substrWithAtMostK(const string& s, int k) {
    vector<int> freq(26, 0);
    long long num = 0;
    size_t left = 0, distinct = 0;
    
    for (size_t right = 0; right < s.size(); ++right) {
        if (freq[s[right] - 'a']++ == 0) ++distinct;
        
        while (distinct > k) {
            if (--freq[s[left] - 'a'] == 0) --distinct;
            ++left;
        }
        
        num += right - left + 1;
    }
    return num;
}

long long int substrCount (string s, int k) {
// Brute Force
// 	set<char> uniq;
// 	long long int count = 0;
// 	for (int i = 0; i < s.size(); i++) {
// 	    for (int j = i; j < s.size(); j++) {
// 	        uniq.insert(s[j]);
// 	        if (uniq.size() == k) count++; 
// 	    }
// 	    uniq.clear();
// 	}
// 	return count;

// Optimized 
return substrWithAtMostK(s, k) - substrWithAtMostK(s, k - 1);

}

int main() {
    
    return 0;
}