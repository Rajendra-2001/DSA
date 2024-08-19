
#include <iostream>

using namespace std;
int minSteps(int n)
{
  int ans = 0;
  for (int i = 2; i <= n; ++i)
  {
    while (n % i == 0)
    {
      ans += i;
      n /= i;
    }
  }
  return ans;
}

int main()
{
  int n1 = 18;
  int n2 = 3;
  int n3 = 100;
  int n4 = 1;

  cout << "Minimum steps for " << n1 << ": " << minSteps(n1) << endl;
  cout << "Minimum steps for " << n2 << ": " << minSteps(n2) << endl;
  cout << "Minimum steps for " << n3 << ": " << minSteps(n3) << endl;
  cout << "Minimum steps for " << n4 << ": " << minSteps(n4) << endl;

  return 0;
}
