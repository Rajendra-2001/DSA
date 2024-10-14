#include <iostream>
#include <vector>
#include <queue>
#include <cmath> // For ceil

using namespace std;

long long maxKelements(vector<int> &nums, int k)
{
  // Create a max-heap priority queue
  priority_queue<int> pq;
  long long score = 0; // Use long long for large values

  // Push elements of the vector 'nums' into the priority queue
  for (int num : nums)
  {
    pq.push(num);
  }

  // Process the queue 'k' times
  while (k > 0)
  {
    // Add the top element to the score
    score += pq.top();
    int x = pq.top();
    pq.pop(); // Remove the top element

    // Divide the number by 3 and round up
    x = ceil(x / 3.0); // Use 3.0 to perform floating-point division
    pq.push(x);        // Push the modified value back into the priority queue

    k--; // Decrease the number of iterations left
  }

  return score;
}

int main()
{
  vector<int> nums = {10, 105, 7}; // Example input
  int k = 3;                       // Number of operations

  long long result = maxKelements(nums, k);
  cout << "Maximum score: " << result << endl;

  return 0;
}
