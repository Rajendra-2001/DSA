#include <iostream>

using namespace std;

// Function to calculate the floor of the square root of a number
long long int floorSqrt(long long int n)
{
  if (n == 0 || n == 1)
  {
    return n;
  }

  long long start = 1, end = n, ans = 0;
  while (start <= end)
  {
    long long mid = (start + end) / 2;

    // Check if mid*mid is equal to n
    if (mid * mid == n)
    {
      return mid;
    }

    // If mid*mid is less than n, discard the left half
    if (mid * mid < n)
    {
      start = mid + 1;
      ans = mid; // Store the floor value of sqrt(n)
    }
    // If mid*mid is greater than n, discard the right half
    else
    {
      end = mid - 1;
    }
  }
  return ans;
}

// Driver code
int main()
{
  long long n;

  cout << "Enter a number: ";
  cin >> n;

  long long result = floorSqrt(n);
  cout << "The floor of the square root of " << n << " is: " << result << endl;

  return 0;
}
