//Brute Force of 3 Sum problem 
//Approach is Using 2 pointer
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        set<vector<int>>s;
        for(int i = 0;i < n;i++) {
            for(int j = i + 1;j < n;j++) {
                for(int k = j + 1;k < n;k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int>triplet = {nums[i],nums[j],nums[k]};
                        sort(triplet.begin(),triplet.end());
                        if(s.find(triplet) == s.end()) {
                            s.insert(triplet);
                            ans.push_back(triplet);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

//I am going to use Better Approach 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n;i++) {
            if(i != 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = n - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) {
                    j++;
                }
                else if(sum > 0) {
                    k--;
                }
                else {
                    vector<int>temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j - 1]) j++;
                    while(j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};