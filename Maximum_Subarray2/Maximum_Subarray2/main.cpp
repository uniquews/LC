//
//  main.cpp
//  Maximum_Subarray2
//
//  Created by Shuai Wang on 9/3/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int maxSubArray(vector<int> A) {
//        if (A.size() == 0) {
//            return 0;
//        }
//        
//        int result = INT_MIN;
//        int prevSum = 0;
//        vector<int> sum(A.size(), 0);
//        for (int i = 0; i < A.size(); i++) {
//            sum[i] = prevSum + A[i];
//            prevSum = sum[i];
//        }
//        
//        vector<int> maxLeft(A.size());
//        int valley = 0;
//        maxLeft[0] = sum[0];
//        for (int i = 1; i < A.size(); i++) {
//            maxLeft[i] = max(sum[i] - valley, maxLeft[i - 1]);
//            valley = min (sum[i], valley);
//        }
//        
//        vector<int> maxRight(A.size());
//        int peek = sum[A.size() - 1];
//        maxRight[A.size() - 1] = 0;
//        
//        for (int i = (int)A.size() - 2; i >= 0; i--) {
//            maxRight[i] = max(maxRight[i + 1], peek - sum[i]);
//            peek = max(peek, sum[i]);
//        }
//        
//        for (int i = 0; i < A.size() - 1; i++) {
//            
//            if (maxLeft[i] + maxRight[i + 1] > result) {
//                result = maxLeft[i] + maxRight[i];
//            }
//        }
//        
//        return result;
//        
//        
//    }
//
//
//};

class Solution {
    
public:
    int maxTwoSubArrays(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int result = INT_MIN;
        int n = (int)nums.size();
        vector<int> maxLeft(n + 1, INT_MIN);
        vector<int> maxRight(n + 1, INT_MIN);
        vector<int> profit(n + 1, 0);
        
        vector<int> sum(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        
        maxLeft[0] = INT_MIN;
        for (int i = 1, valley = 0; i < sum.size(); i++) {            
            maxLeft[i] = max(maxLeft[i - 1], sum[i] - valley);
            valley = min(valley, sum[i]);
        }
        
        
        for (int i = n, peak = sum[n]; i > 0; i--) {
            if (i == n) {
                maxRight[i] = peak - sum[i - 1];
            } else {
                maxRight[i]= max(maxRight[i + 1], peak - sum[i - 1]);
            }
            peak = max(peak, sum[i - 1]);
        }
        
        for (int i = 1; i < n; i++) {
            profit[i] = maxLeft[i] + maxRight[i + 1];
            result = max(result, profit[i]);
        }
        
        return result;
    }
    
};

int main(int argc, const char * argv[])
{

    Solution su;
//    vector<int> A = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> A = {1,3,-1,2,-1,2};
//    vector<int> A = {5,4,3,2,1,10};
//    vector<int> A = {-1,-2,-3,10,-4,-1};
//    vector<int> A = {-1,-2,-3,-100,-1,-50};
    cout << su.maxTwoSubArrays(A) << endl;
    return 0;
}

