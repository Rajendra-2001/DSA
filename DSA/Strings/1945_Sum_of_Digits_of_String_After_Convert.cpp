#include <iostream>
#include <string>

using namespace std;

int getLucky(string s, int k)
{
  string transformed = "";
  for (char ch : s)
  {
    int num = ch - 'a' + 1;
    transformed += to_string(num);
  }

  int sum = 0;
  for (char ch : transformed)
  {
    sum += ch - '0';
  }

  while (--k > 0)
  {
    int newSum = 0;
    while (sum > 0)
    {
      newSum += sum % 10;
      sum /= 10;
    }
    sum = newSum;
  }

  return sum;
}

int main()
{
  string s = "leetcode";
  int k = 2;
  cout << "The final result is: " << getLucky(s, k) << endl;
  return 0;
}
