#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
  // Initialize variables and arrays
  int i = 0;
  int j = 0;
  int size1 = nums1.size();
  int size2 = nums2.size();
  int size = size1 + size2;
  vector<int> nums(size); // Combined array to store sorted elements from nums1 and nums2
  int k = 0;
  double median;

  // Merge the arrays nums1 and nums2 into the combined array nums
  while (i < size1 && j < size2)
  {
    if (nums1[i] < nums2[j])
    {
      nums[k] = nums1[i];
      i++;
    }
    else
    {
      nums[k] = nums2[j];
      j++;
    }
    k++;
  }

  // Copy remaining elements from nums1 if any
  if (i < size1)
  {
    while (i < size1)
    {
      nums[k] = nums1[i];
      i++;
      k++;
    }
  }
  // Copy remaining elements from nums2 if any
  else
  {
    while (j < size2)
    {
      nums[k] = nums2[j];
      j++;
      k++;
    }
  }

  // Calculate the median based on the size of the combined array
  if (size % 2 != 0)
  {
    median = nums[((size + 1) / 2) - 1] / 1.0;
  }
  else
  {
    median = (nums[((size) / 2) - 1] + nums[(size / 2)]) / 2.0;
  }
  return median;
}

int main()
{
  vector<int> nums1 = {1, 3};
  vector<int> nums2 = {2};

  double median = findMedianSortedArrays(nums1, nums2);
  cout << "The median is: " << median << endl;

  // Add more test cases if needed
  vector<int> nums3 = {1, 2};
  vector<int> nums4 = {3, 4};
  median = findMedianSortedArrays(nums3, nums4);
  cout << "The median is: " << median << endl;

  vector<int> nums5 = {0, 0};
  vector<int> nums6 = {0, 0};
  median = findMedianSortedArrays(nums5, nums6);
  cout << "The median is: " << median << endl;

  vector<int> nums7 = {};
  vector<int> nums8 = {1};
  median = findMedianSortedArrays(nums7, nums8);
  cout << "The median is: " << median << endl;

  vector<int> nums9 = {2};
  vector<int> nums10 = {};
  median = findMedianSortedArrays(nums9, nums10);
  cout << "The median is: " << median << endl;

  return 0;
}
