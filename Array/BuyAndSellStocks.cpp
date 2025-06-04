#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int BuyPrice = prices[0];
        int SellPrice = 0;
        //ab main traverse karoonga
        for(int i = 0;i < prices.size();i++) {
            if(BuyPrice > prices[i]) {
                //If today's price is lower than any we've seen so far, it's a better day to buy, so we update BuyPrice.
                BuyPrice = prices[i];
            }
            // If we sell on today, and had bought at BuyPrice, what’s the profit?
            // If this profit is better than our current SellPrice (max profit so far), we update it.
            SellPrice = max(SellPrice,prices[i] - BuyPrice);
        }
        return SellPrice;
    }
};