//
//  main.cpp
//  Gas_Station
//
//  Created by Shuai Wang on 9/3/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.size() == 0 || cost.size() == 0) {
            return 0;
        }
        
        vector<int> diff(gas.size());
        for (int i = 0; i < gas.size(); i++) {
            diff[i] += gas[i] - cost[i];
        }
        
        //其实就是在0到n之间，找到第一个连续子序列（这个子序列的结尾必然是n）大于0的。
        int total = 0;
        int sum = 0;
        int start = 0;
        for (int i = 0; i < diff.size(); i++) {
            total += diff[i];
            sum += diff[i];
            if (sum < 0) {
                sum = 0;
                start = i + 1;
            }
        }
        
        if (total >= 0) {
            return start;
        } else {
            return -1;
        }
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

