// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution
{
public:
  int findExtra(int n, int arr1[], int arr2[])
  {
    // This function finds the index of the extra element in arr1.
    int high = n - 1; // Initialize the high pointer to the last index of arr1
    int low = 0;      // Initialize the low pointer to the first index of arr1

    // Perform binary search
    while (low < high)
    {
      int mid = (low + high) / 2; // Calculate the mid index

      // Compare elements at the mid index of arr1 and arr2
      if (arr2[mid] == arr1[mid])
      {
        // If they are equal, it means the extra element is in the right half
        low = mid + 1;
      }
      else
      {
        // If they are not equal, it means the extra element is in the left half or at mid
        high = mid;
      }
    }

    // After the loop, low will be pointing to the index of the extra element
    return low;
  }
};

// { Driver Code Starts.
int main()
{
  int t; // Number of test cases
  cin >> t;

  while (t--)
  {
    int n; // Size of the array arr1
    cin >> n;

    int arr1[n], arr2[n - 1]; // Declare the arrays arr1 and arr2

    for (int i = 0; i < n; i++)
    {
      cin >> arr1[i]; // Input elements for arr1
    }

    for (int i = 0; i < n - 1; i++)
    {
      cin >> arr2[i]; // Input elements for arr2
    }

    Solution obj;
    cout << obj.findExtra(n, arr1, arr2) << endl; // Call the function and print the result
  }
}
// } Driver Code Ends
