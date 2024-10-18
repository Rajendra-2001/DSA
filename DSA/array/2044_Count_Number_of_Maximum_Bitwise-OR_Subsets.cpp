#include <vector>
#include <iostream>
using namespace std;

int solve(int ind, int or_val, int max_or, vector<int>& nums) {
    // Base case: if we have processed all elements
    if (ind == nums.size()) {
        return (max_or == or_val) ? 1 : 0;
    }

    // Recursively explore two choices:
    // 1. Pick the current element and update the OR value.
    int pick = solve(ind + 1, or_val | nums[ind], max_or, nums);

    // 2. Don't pick the current element and keep the same OR value.
    int not_pick = solve(ind + 1, or_val, max_or, nums);

    // Return the total count of valid subsets
    return pick + not_pick;
}

int countMaxOrSubsets(vector<int>& nums) {
    int max_or = 0;

    // Calculate the maximum OR value of all elements in the array
    for (auto &i : nums) {
        max_or |= i;
    }

    // Start the recursive process from index 0 with OR value 0
    return solve(0, 0, max_or, nums);
}

int main() {
    vector<int> nums = {3, 1, 5, 6};
    
    // Call the function and print the result
    cout << "Number of subsets with maximum OR value: " << countMaxOrSubsets(nums) << endl;
    
    return 0;
}
