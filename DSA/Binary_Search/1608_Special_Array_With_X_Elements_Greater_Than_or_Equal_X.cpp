class Solution
{
public:
  // SC: O(n)
  int count(vector<int> &nums, int target)
  {
    int ans = 0;
    for (int num : nums)
    {
      if (num >= target)
        ans++;
    }
    return ans;
  }

  int specialArray(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());

    int start = 0;
    int end = nums.size();

    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      int ans = count(nums, mid);

      if (ans == mid)
        return mid;
      else if (ans > mid)
        start = mid + 1;
      else
        end = mid - 1;
    }

    return -1;
  }

  // SC: O(nlog(n))

  int specialArray(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int l = 0, r = n;
    while (l <= r)
    {
      int mid = l + (r - l) / 2;
      int idx = lower_bound(nums.begin(), nums.end(), mid) - nums.begin();
      int count = n - idx;
      if (count == mid)
        return mid;
      else if (count > mid)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return -1;
  }
};