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

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) {
            return 0;
        }
        
        if (prices.size() == 1) {
            return 0;
        }
        
        vector<int> maxProfit(prices.size());
        int result = INT_MIN;
        
        int valley = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            maxProfit[i] = max(maxProfit[i - 1], prices[i] - valley);
            valley = min(valley, prices[i]);
        }
        
        int peek = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; i--) {
            maxProfit[i] = max(maxProfit[i], maxProfit[i] + peek - prices[i]);
            peek = max(prices[i], peek);
            result = max(maxProfit[i], result);
        }
        
        return result;
    }
    
};

int main(int argc, const char * argv[])
{

    
    
    Solution s;
    vector<int> price = {2,1,2,0,1};
    cout << s.maxProfit(price);
    return 0;
}

