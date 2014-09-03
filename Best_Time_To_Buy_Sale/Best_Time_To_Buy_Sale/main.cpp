//
//  main.cpp
//  Best_Time_To_Buy_Sale
//
//  Created by Shuai Wang on 7/10/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>


// fix the sale date and iterate the buy day. Find the min buying price and max profit at the same time
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2) return 0;
        int curMin = 0;
        int profit = 0;
        curMin = prices[0];
        
        for(int i=1; i<prices.size(); i++){
            profit = max(profit, prices[i] - curMin);
            curMin = min(curMin, prices[i]);
        }
        
        return profit;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

