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
    
        int n = (int)nums.size();
        vector<vector<int>> f(n + 1, vector<int> (k + 1, 0));
        
        f[0][0] = 0;
        for (int i = 1; i <= k; i++) {
            f[0][i] = INT_MIN;
        
        }
        
        for (int i = 1; i <= k; i++) {
            f[i][0] = 0;
        }
        
        vector<vector<int>> profit(n + 1, vector<int> (n + 1, 0));
        profit[0][0] = 0;
        
        for (int i = 1; i <= n; i++) {
            profit[i][i] = 0;
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <=n; j++) {
                profit[i][j] = nums[j - 1] - nums[i - 1];
            }
        }
        
        //f[i][j] 表示第i天之前做了j次交易 = 第l天之前做了j - 1次交易，加上l + 1天到i天的Profit
        for (int i = 1; i <= k; i++) {
            
            for (int j = 2; j <= n; j++) {  // 从第二天开始才可以做完整的交易
                if (i < j) {
                    for (int l = 0; l <= j - 2; l++) {
                        f[j][i] = max(f[l][i - 1] + profit[l + 1][j], f[j - 1][i]);
                    }
                
                }
                
            }
         
        }
        
        return f[n][k];
        
    }

};

int main(int argc, const char * argv[])
{

    vector<int> nums = {3,2,6,5,0,3};
    Solution su;
    cout << su.beststock(nums, 2) << endl;
    return 0;
}

