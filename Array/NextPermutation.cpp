// 💡 Intuition (How to solve it):
// To find the next permutation:

// Find the first decreasing element from the end.

// Find the element just larger than it (again from the end).

// Swap them.

// Reverse the suffix (the part after the position you swapped).

// 🧠 Step-by-step Algorithm:
// Suppose: nums = [1, 3, 5, 4, 2]

// Step 1: Find the first index i from the end where nums[i] < nums[i+1]
// Start from the end: 4 > 2 ✅

// 5 > 4 ✅

// 3 < 5 ❌ ← Stop here, i = 1

// Step 2: Find index j from the end where nums[j] > nums[i]
// Go from the end: 2 < 3, 4 > 3 ← So j = 3

// Step 3: Swap nums[i] and nums[j]
// Swap nums[1] and nums[3]: [1, 4, 5, 3, 2]

// Step 4: Reverse the subarray from i+1 to the end
// Reverse [5, 3, 2] → [2, 3, 5]

// ✅ Final result: [1, 4, 2, 3, 5]


#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Step 1: Find the first decreasing element from the end
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    // Step 2: If such an element was found, find just larger element and swap
    if (i >= 0) {
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }

    // Step 3: Reverse the subarray from i+1 to end
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    vector<int> nums = {1, 2, 3};
    
    nextPermutation(nums);
    
    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}
