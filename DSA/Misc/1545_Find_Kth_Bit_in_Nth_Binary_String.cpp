#include <iostream>
#include <algorithm>
using namespace std;

// Function to invert and reverse a binary string
string invertString(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') s[i] = '1';
        else s[i] = '0';
    }
    reverse(s.begin(), s.end());
    return s;
}

// Function to generate the binary string S_n
string nthBinary(int n) {
    if (n == 1) return "0";
    string prev = nthBinary(n - 1);
    return prev + "1" + invertString(prev);
}

// Function to find the k-th bit in S_n
char findKthBit(int n, int k) {
    string s = nthBinary(n);
    return s[k - 1];  // k is 1-indexed, so we use k-1 for 0-indexing
}

int main() {
    int n = 3, k = 5;
    cout << "The " << k << "-th bit in S_" << n << " is: " << findKthBit(n, k) << endl;
    return 0;
}
