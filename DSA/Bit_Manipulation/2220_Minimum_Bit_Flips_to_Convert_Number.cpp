#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal)
{
  int xor_value = start ^ goal; // XOR the two numbers to find differing bits
  int res = 0;                  // Initialize the result (number of bit flips)

  // Count the number of set bits (1s) in xor_value
  while (xor_value > 0)
  {
    res += xor_value & 1; // If the last bit is 1, it adds to the number of flips
    xor_value >>= 1;      // Right-shift to check the next bit
  }

  return res; // Return the number of bit flips
}

int main()
{
  int start = 10;
  int goal = 12;
  cout << minBitFlips(start, goal);
}