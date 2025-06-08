//MERE PURE QUESTIONS KA LOGIC

// First find the largest element in an array which is the pivot point. The element just after the largest element is the smallest element. Once we have the indices of the largest and the smallest elements, we use two pointer technique to find the pair. 

// Set the left pointer(l) to the smallest value and the right pointer(r) to the highest value.

// To handle the circular nature of the rotated array, we will use the modulo operation with the array size.

// While l ! = r, we shall keep checking if arr[l] + arr[r] = target.
// If arr[l] + arr[r] > target, update r = (r - 1 + n) % n.
// If arr[l] + arr[r] < target, update l = (l + 1) % n.
// If arr[l] + arr[r] = target, then return true.
// If no such pair is found after the iteration is complete, return false.

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        int n = arr.size();

        // Find the pivot element
        int i;
        for (i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                break;
            }
        }

        // l is now index of smallest element
        int l = (i + 1) % n;

        // r is now index of largest element
        int r = i;

        // Keep moving either l or r till they meet
        while (l != r) {

            // If we find a pair with sum target, return true
            if (arr[l] + arr[r] == target) {
                return true;
            }

            // If current pair sum is less, move to higher sum
            if (arr[l] + arr[r] < target) {
                l = (l + 1) % n;
            }

            // Move to lower sum
            else {
                r = (r - 1 + n) % n;
            }
        }

        return false;
    }
};
