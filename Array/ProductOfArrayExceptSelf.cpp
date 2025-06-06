//I am going to right down the brute force code 
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //mujhe yahan ans return krna tha vector ke form mein isilye maine yahan ans ka vector create kiya h
        vector<int>ans;
        int n = nums.size();
        for(int i = 0;i < n;i++) {
            int product = 1;
            for(int j = 0;j < n;j++) {
                if(i != j) {
                    product *= nums[j];
                }
            }
            ans.push_back(product);
        }
        return ans;
    }
};

// Now I am going to right down the Most optimal Code 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);
        for(int i = 1;i < n;i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }//ab main yahan suffix calculate karoonga
        int suffix = 1;
        for(int i = n - 1;i >= 0;i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        return ans;
    }
};