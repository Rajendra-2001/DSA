#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

// Function to perform the backtracking
int backtrack(int ind, string &s, unordered_set<string>& st) {
    if (ind == s.size()) return 0;
    
    int ans = 0;
    for (int i = ind + 1; i <= s.size(); i++) {
        string substring = s.substr(ind, i - ind);  // Extract the substring from ind to i
        if (st.find(substring) == st.end()) {  // If substring not already in the set
            st.insert(substring);  // Insert the substring
            ans = max(ans, 1 + backtrack(i, s, st));  // Maximize the result
            st.erase(substring);  // Backtrack by removing the substring
        }
    }
    return ans;
}

// Wrapper function to start the backtracking
int maxUniqueSplit(string s) {
    unordered_set<string> st;
    return backtrack(0, s, st);
}

// Driver code
int main() {
    string s1 = "ababccc";  // Expected output: 5 (["a", "b", "ab", "c", "cc"])
    string s2 = "aba";      // Expected output: 2 (["a", "ba"] or ["ab", "a"])
    
    cout << "Max unique splits for '" << s1 << "' : " << maxUniqueSplit(s1) << endl;
    cout << "Max unique splits for '" << s2 << "' : " << maxUniqueSplit(s2) << endl;

    return 0;
}
