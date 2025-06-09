// 🔷 Key Intuition:
// To merge intervals, the most important idea is:

// If two intervals overlap, we can merge them into one. If they don’t, we just add the new interval to the result.

// But to do this efficiently, we must first sort the intervals by their start time.

// ⚙️ Why Sorting Works?
// By sorting intervals by their start times, we ensure that:

// All overlapping intervals will be next to each other in the list.

// We don’t need to go back and check previous intervals — we just process them in order.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //pehle main sort krdoonga jisse ki saare aas pass aajaye
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        //ab main traverse karoonga
        for(int i = 0;i < intervals.size();i++) {
            //ab mera do cases banega ki main insert kr skte h ki nhi 
            if(ans.empty() || ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};

// THIS IS THE SOLUTION WHOSE TIME COMPLEXITY IS O(n logn) and Space complexity of this solutionn is O(n) Which can be futher optimize to O(1) which is In-Place method

//MOst optimal Solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int index = 0;
        for(int i = 1;i < intervals.size();i++) {
            if(intervals[index][1] >= intervals[i][0]) {
                //toh ab main merge kr skta hoon
                intervals[index][1] = max(intervals[index][1], intervals[i][1]); 
            }
            else {
                index++;
                intervals[index] = intervals[i];
            }
        }
        intervals.resize(index + 1);
        return intervals;
    }
};