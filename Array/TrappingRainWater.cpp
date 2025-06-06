//This is the Better Approach we can use it but its T.C is O(n) and its space complexity is O(n) which is not good interviewer will ask to optimize it
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        //pehle main do vector create kr loonga jime main prefix aur suffix array store karoonga
        vector<int>lmax(n,0);
        vector<int>rmax(n,0);
        lmax[0] = height[0];
        rmax[n - 1] = height[n - 1];
        //ab  main pehle loop chalaoonga jisma main calculate karoonga prefix sum
        for(int i = 1;i < n;i++) {
            lmax[i] = max(lmax[i - 1],height[i]);
        }
        //ab yeh mera doosra loop h jisme main suffix sum store karoonga
        for(int i = n - 2;i >= 0;i--) {
            rmax[i] = max(rmax[i + 1],height[i]);
        }
        //ab main ek ans create kroonga jisme main ans store karoonga
        int ans = 0;
        for(int i = 0;i < n;i++) {
            ans += min(lmax[i],rmax[i]) - height[i];
        }
        //ab main last mein ans ko return kardoonga
        return ans;
    }
};

// Now I am going to Write down the most Optimal Approach
//which is Two pointer approach
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0,right = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;
        while(left < right) {
            leftMax = max(leftMax,height[left]);
            rightMax = max(rightMax,height[right]);
            if(leftMax < rightMax) {
                //iska mtlb ki left part chota h mujhe chote se hi mtlb h 
                ans += (leftMax - height[left]);
                left++;
            }
            else {
                //iska mtlb ki right part chota h
                ans += (rightMax - height[right]);
                right--;
            }
        }
        return ans;
    }
};