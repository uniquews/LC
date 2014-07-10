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
        if(prices.size()<2) return 0;
        int diff = 0;
        int sum = 0;
        for(int i =0; i<prices.size(); i++){
            diff = prices[i] - prices[i-1];
            if(diff >0)
                sum +=diff;
        }
        
        return sum;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

