#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
  int n = s.size();
  int ans = 0;
  int sign = 1; // Assume positive number by default
  int i = 0;

  // Step 1: Skip leading spaces
  while (i < n && s[i] == ' ')
  {
    i++;
  }

  // Step 2: Check for optional sign
  if (i < n && (s[i] == '-' || s[i] == '+'))
  {
    sign = (s[i] == '-') ? -1 : 1;
    i++;
  }

  // Step 3: Convert characters to integer, ensuring the characters are digits
  while (i < n && s[i] >= '0' && s[i] <= '9')
  {
    int digit = s[i] - '0';

    // Step 4: Handle overflow and underflow
    if (ans > (INT_MAX - digit) / 10)
    {
      return (sign == 1) ? INT_MAX : INT_MIN;
    }

    ans = ans * 10 + digit;
    i++;
  }

  return ans * sign;
}

int main()
{
  string st = "-248";
  cout << myAtoi(st);
}