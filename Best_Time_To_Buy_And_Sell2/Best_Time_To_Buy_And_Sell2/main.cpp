//
//  main.cpp
//  Best_Time_To_Buy_And_Sell2
//
//  Created by Shuai Wang on 7/10/14.
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
        
        int sum = 0;
        for (int i = 1; i < prices.size(); i++) {
            int tmp = prices[i] - prices[i - 1];
            if (sum > 0) {
                sum += tmp;
            }
            
        }
        
        return sum;
    }
};

int main(int argc, const char * argv[])
{

    vector<int> p = {1,2};
    Solution su;
    su.maxProfit(p);
    return 0;
}

