//
//  main.cpp
//  Best Stock 4
//
//  Created by Shuai Wang on 10/6/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace  std;

class Solution {
public:
    
    int beststock(vector<int> &nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }
    
        int days = (int)nums.size();
        vector<vector<int>> f(days + 1, vector<int> (k + 1, 0));
        
        vector<vector<int>> profit(days + 1, vector<int> (days + 1, 0));
        profit[0][0] = 0;
        
        for (int i = 1; i <= days; i++) {
            profit[i][i] = 0;
        }
        
        for (int i = 1; i < days; i++) {
            for (int j = i + 1; j <=days; j++) {
                profit[i][j] = nums[j - 1] - nums[i - 1];
            }
        }
        
        //f[i][j] 表示第i天之前做了j次交易 = 第l天之前做了j - 1次交易，加上l + 1天到i天的Profit
        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= nums.size(); i++) {
                for (int n = 1; n <= i; n++) {
                    f[i][j] = max(f[i][j], max(f[i - n][j], f[i - n][j - 1] + profit[i - n + 1][i]));
                }
            }
        }
        
        return f[days][k];
        
    }

};

int main(int argc, const char * argv[])
{

//    vector<int> nums = {3,2,6,5,0,3};
    vector<int> nums = {5,4,3,2,1,10};
//    vector<int> nums = {1,3,5,3,7,8,4,2,9};
    Solution su;
    cout << su.beststock(nums, 2) << endl;
    return 0;
}

