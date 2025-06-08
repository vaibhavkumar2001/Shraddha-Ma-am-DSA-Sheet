//Hm intution kaise find kr skte h woh ab main likhoonga yahan pe

// Two Sorted Parts:
// After rotation, the array is broken into two sorted subarrays:

// [4, 5, 6] and [1, 2, 3] → both sorted individually.

// Only One Point of Disruption:
// There is exactly one point where the order breaks. This is the pivot.

// In [4, 5, 6, 1, 2, 3], it breaks from 6 -> 1.

// Pivot Property:
// The pivot element is the largest and is followed by the smallest element.

// Binary Search Clue:

// You can still use binary search by identifying which half of the array is sorted at any point.

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int ans = INT_MAX;
        while(start <= end) {
            int mid = (start + end)/2;
            if(nums[start] <= nums[mid]) {
                ans = min(ans,nums[start]);
                start = mid + 1;
            }
            else {
                //right part is sorted
                ans = min(ans,nums[mid]);
                end = mid - 1;
            }
        }
        return ans;
    }
};