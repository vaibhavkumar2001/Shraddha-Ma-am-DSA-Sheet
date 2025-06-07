//This solution which i am going to use is Brute Force this will give me TLE so i will optimize it later on

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int MaxWater = 0;
        int n = height.size();
        for(int i = 0;i < n;i++) {
            for(int j = i + 1;j < n;j++) {
                //ab main width nikaloonga
                int width = j - i;
                //height main sbse choti wali ko loonga kyonki choti wali wall hi decide karenga ki kitna water store karega 
                int ht = min(height[i],height[j]);
                int area = width * ht;
                MaxWater = max(MaxWater,area);
            }
        }
        return MaxWater;
    }
};

// Most Optimize Approach 
