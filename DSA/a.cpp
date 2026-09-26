#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <bits/stdc++.h>
using namespace std;
#include <vector>
using namespace std;

#include <iostream>
#include <cctype>
using namespace std;

vector<int> flipZero(vector<int> arr)
{
  int n = arr.size();
  int i = 0, j = n - 1;
  while (i <= j)
  {
    if (arr[j] == 0)
    {
      j--;
    }
    if (arr[i] == 0)
    {
      swap(arr[i], arr[j]);
      i++;
      j--;
    }
    i++;
  }
  return arr;
}

int main()
{
  vector<int> arr = {7, 0, 4, 0, 0, 8, 5, 1};

  flipZero(arr);
  for (auto i : arr)
    cout << i << "";
  return 0;
}
