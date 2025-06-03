// C++ program to solve chocolate distribution
// problem using Sliding Window

// 🧠 Problem Summary:
// You are given an array of integers, arr[], where each element is the number of chocolates in a packet.

// You have m students and need to give one packet to each student.

// Your goal is to choose m packets such that the difference between the max and min chocolates in those packets is as small as possible.

// 🔍 Step-by-Step Intuition:
// 1. What does the problem want?
// We are trying to minimize the difference between the max and min in any subset of m packets.

// 2. Can we brute force it?
// Yes, but it would be very inefficient:


// 3. Is there a pattern or shortcut?
// Yes! Think about this:

// If we sort the array, then the elements that are close together (i.e., in a sliding window) are most likely to have small differences between max and min.

// Once sorted, you just have to look at all contiguous subarrays (windows) of size m.

// 💡 That’s the key insight:
// After sorting, the optimal group of m packets must lie in some contiguous subarray of size m.

// 🪟 Sliding Window Approach:
// Sort the array.

// Slide a window of size m from index 0 to n - m.

// For each window:

// Difference = arr[i + m - 1] - arr[i]

// Keep track of the minimum difference.

// ✅ Why it works:
// After sorting, the smallest range of m packets will be in a window of m consecutive sorted elements. This is because spreading the elements apart would increase the max-min difference.

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int findMinDiff(vector<int> &arr, int m) {
	int n = arr.size();
  
    // Sort the given packets
    sort(arr.begin(), arr.end());

    int minDiff = INT_MAX;

    for (int i = 0; i + m - 1 < n; i++) {
      	
      	// calculate difference of current window
        int diff = arr[i + m - 1] - arr[i];
      
      	// if current difference is smaller
      	// then update the minimum difference
        if (diff < minDiff)
        	minDiff = diff;
    }
    return minDiff;
}

int main() {
    vector<int> arr = {7, 3, 2, 4, 9, 12, 56};
    int m = 3;
  	
    cout << findMinDiff(arr, m);
    return 0;
}