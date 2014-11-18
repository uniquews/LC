//
//  main.cpp
//  Best_Stock3
//
//  Created by Shuai Wang on 6/27/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int maxProfit(vector<int> &prices) {
//        if (prices.size() == 0) {
//            return 0;
//        }
//        
//        if (prices.size() == 1) {
//            return 0;
//        }
//        
//        vector<int> maxProfit(prices.size());
//        int result = INT_MIN;
//        
//        int valley = prices[0];
//        for (int i = 1; i < prices.size(); i++) {
//            maxProfit[i] = max(maxProfit[i - 1], prices[i] - valley);
//            valley = min(valley, prices[i]);
//        }
//        
//        int peek = prices[prices.size() - 1];
//        for (int i = prices.size() - 2; i >= 0; i--) {
//            maxProfit[i] = max(maxProfit[i], maxProfit[i] + peek - prices[i]);
//            peek = max(prices[i], peek);
//            result = max(maxProfit[i], result);
//        }
//        
//        return result;
//    }
//    
//};

//class Solution {
//public:
//    int maxProfit(vector<int> &prices) {
//        if (prices.size() <= 1) {
//            return 0;
//        }
//        
//        int n = (int)prices.size();
//        int result = 0;
//        vector<int> profit(n, 0);
//        profit[0] = 0;
//        for (int i = 1, valley = prices[0]; i < n; i++) {
//            profit[i] = max(profit[i - 1], prices[i] - valley);
//            
//            if (prices[i] < valley) {
//                valley = prices[i];
//            }
//        }
//        
//        for (int i = n - 2, peak = prices[n - 1]; i >= 0; i--) {
//            if (i == 0) {
//                profit[i] = peak - prices[0];
//            } else {
//                profit[i] = peak - prices[i] + profit[i - 1];
//                if (prices[i] > peak) {
//                    peak = prices[i];
//                }
//            }
//            
//            result = max(result, profit[i]);
//        }
//        
//        return result;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0 || prices.size() == 1) {
            return 0;
        }
        
        vector<int> profit(prices.size());
        int result = 0;
        int valley = prices[0];
        profit[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit[i] = max(profit[i - 1], prices[i] - valley);
            valley = min(valley, prices[i]);
        }
        
        int peak = prices[prices.size() - 1];
        for (int i = (int)prices.size() - 2; i >= 0; i--) {
            profit[i] = max(profit[i], peak - prices[i + 1] + profit[i]);
            peak = max(peak, prices[i]);
        }
        
        for (int i = 0; i < profit.size(); i++) {
            result = max(result, profit[i]);
        }
        
        return result;
        
    }
};
int main(int argc, const char * argv[])
{

    
    
    Solution s;
//    vector<int> price = {3,2,6,5,0,3};
    vector<int> price = {5,4,3,2,1,10};
    cout << s.maxProfit(price);
    return 0;
}

