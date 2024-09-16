#include <bits/stdc++.h>
using namespace std;
int minuteConversion(string st)
{
  int min = (10 * (st[0] - '0') + (st[1] - '0')) * 60 + (10 * (st[3] - '0') + (st[4] - '0'));
  return min;
}

int findMinDifference(vector<string> &timePoints)
{
  // Step 1: Convert time points to minutes
  vector<int> minute(timePoints.size(), -1);
  for (int i = 0; i < timePoints.size(); i++)
  {
    minute[i] = minuteConversion(timePoints[i]);
  }

  // Step 2: Sort the time points in minutes
  sort(minute.begin(), minute.end());

  // Step 3: Find the minimum difference between consecutive time points
  int min_ = INT_MAX;
  for (int i = 0; i < minute.size() - 1; i++)
  {
    min_ = min(min_, minute[i + 1] - minute[i]);
  }

  // Step 4: Handle the wrap-around case (difference between last and first time point across midnight)
  int wrapAroundDiff = (1440 - minute.back()) + minute[0];
  min_ = min(min_, wrapAroundDiff);

  return min_;
}

int main()
{
  // Example usage
  vector<string> timePoints = {"23:59", "00:00", "12:34"};
  cout << "Minimum time difference: " << findMinDifference(timePoints) << endl;
  return 0;
}
