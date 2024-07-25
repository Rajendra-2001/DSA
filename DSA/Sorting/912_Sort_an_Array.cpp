#include <iostream>
#include <vector>

using namespace std;

// Function to merge two halves of the array
void merge(vector<int> &nums, int low, int mid, int high)
{
  vector<int> temp;
  int left = low;
  int right = mid + 1;

  // Merge the two halves into temp
  while (left <= mid && right <= high)
  {
    if (nums[left] <= nums[right])
    {
      temp.push_back(nums[left++]);
    }
    else
    {
      temp.push_back(nums[right++]);
    }
  }

  // Copy any remaining elements from the left half
  while (left <= mid)
  {
    temp.push_back(nums[left++]);
  }

  // Copy any remaining elements from the right half
  while (right <= high)
  {
    temp.push_back(nums[right++]);
  }

  // Copy the sorted elements back to the original array
  for (int i = low; i <= high; i++)
  {
    nums[i] = temp[i - low];
  }
}

// Recursive function to perform merge sort
void mergeSort(vector<int> &nums, int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
  }
}

// Function to sort the array using merge sort
vector<int> sortArray(vector<int> &nums)
{
  mergeSort(nums, 0, nums.size() - 1);
  return nums;
}

// Driver code
int main()
{
  vector<int> nums = {38, 27, 43, 3, 9, 82, 10};

  cout << "Original array:" << endl;
  for (int num : nums)
  {
    cout << num << " ";
  }
  cout << endl;

  sortArray(nums);

  cout << "Sorted array:" << endl;
  for (int num : nums)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
