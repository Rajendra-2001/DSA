#include <string>
#include <numeric>
#include <bits/stdc++.h>
using namespace std;

string fractionAddition(string exp)
{
  int numerator = 0, denominator = 1; // Start with 0/1 as the initial fraction
  int i = 0;
  int n = exp.size();

  while (i < n)
  {
    // Determine the sign
    int sign = 1;
    if (exp[i] == '-' || exp[i] == '+')
    {
      if (exp[i] == '-')
        sign = -1;
      i++;
    }

    // Parse the numerator
    int num = 0;
    while (i < n && isdigit(exp[i]))
    {
      num = num * 10 + (exp[i] - '0');
      i++;
    }
    num *= sign;

    // Skip the '/'
    i++;

    // Parse the denominator
    int den = 0;
    while (i < n && isdigit(exp[i]))
    {
      den = den * 10 + (exp[i] - '0');
      i++;
    }

    // Calculate the new numerator and denominator
    numerator = numerator * den + num * denominator;
    denominator *= den;

    // Simplify the fraction by finding the gcd
    int gcd = abs(__gcd(numerator, denominator));
    numerator /= gcd;
    denominator /= gcd;
  }

  // Convert the result back to a string
  return to_string(numerator) + "/" + to_string(denominator);
}
int main()
{
  string st = "1/2+2/5-3/2";
  string ans = fractionAddition(st);
  cout << ans;
}