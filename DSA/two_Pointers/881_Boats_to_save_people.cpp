#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the minimum number of rescue boats required
int numRescueBoats(vector<int> &people, int limit)
{
  // Sort the people array to facilitate the two-pointer approach
  sort(people.begin(), people.end());

  int i = 0;                 // Pointer to the lightest person
  int j = people.size() - 1; // Pointer to the heaviest person
  int cnt = 0;               // Counter for the number of boats

  // Loop until all people are placed in boats
  while (i <= j)
  {
    // If the lightest and the heaviest person can share a boat
    if (people[i] + people[j] <= limit)
    {
      i++; // Move to the next lightest person
      j--; // Move to the next heaviest person
    }
    else
    {
      // If they cannot share a boat, the heaviest person gets their own boat
      j--; // Move to the next heaviest person
    }
    cnt++; // Increment the boat count for each iteration
  }
  return cnt; // Return the total number of boats required
}

// Driver code to test the function
int main()
{
  vector<int> people = {3, 2, 2, 1}; // Example input: weights of people
  int limit = 3;                     // Example input: weight limit of each boat

  // Call the function and print the result
  cout << "Minimum number of boats required: " << numRescueBoats(people, limit) << endl;

  return 0;
}
