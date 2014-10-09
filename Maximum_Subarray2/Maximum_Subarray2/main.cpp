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

// Sum数组做法
//class Solution {
//    
//public:
//    int maxTwoSubArrays(vector<int> &nums) {
//        if (nums.size() == 0) {
//            return 0;
//        }
//        
//        int result = INT_MIN;
//        int n = (int)nums.size();
//        vector<int> maxLeft(n + 1, INT_MIN);
//        vector<int> maxRight(n + 1, INT_MIN);
//        vector<int> profit(n + 1, 0);
//        
//        vector<int> sum(n + 1, 0);
//        
//        for (int i = 1; i <= n; i++) {
//            sum[i] = sum[i - 1] + nums[i - 1];
//        }
//        
//        maxLeft[0] = INT_MIN; //有可能第一个数是负数，所以不能初始化为0
//        for (int i = 1, valley = 0; i < sum.size(); i++) {            
//            maxLeft[i] = max(maxLeft[i - 1], sum[i] - valley);
//            valley = min(valley, sum[i]);
//        }
//        
//        
//        for (int i = n, peak = sum[n]; i > 0; i--) {
//            if (i == n) {
//                maxRight[i] = peak - sum[i - 1];  //因为是从n开始，由于n有含义（不像0无含义）。所以这个值其实就是原数组本身的最后一个数字他自己
//            } else {
//                maxRight[i]= max(maxRight[i + 1], peak - sum[i - 1]);
//            }
//            peak = max(peak, sum[i - 1]);  //由于[a,...b]的和是从[a,...b]里取一个peak减去a-1那个位置的sum,所以peak的范围是从sum[i - 1]
//        }
//        
//        for (int i = 1; i < n; i++) {
//            profit[i] = maxLeft[i] + maxRight[i + 1];
//            result = max(result, profit[i]);
//        }
//        
//        return result;
//    }
//    
//};


//普通dp做法 为什么不对（最后枚举n^2才是对的，注意left数组的反例，subarray和subsequence）

class Solution {
public:
    int maxTwoSubArrays(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int n = (int)nums.size();
        vector<int> left(n + 1, 0);
        vector<int> right(n + 1, 0);
        vector<int> total(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            left[i] = max(left[i - 1] + nums[i - 1], nums[i - 1]);
            left[i] = max(left[i - 1], left[i]);
        }
        
        right[n] = nums[n - 1];
        for (int i = n - 1; i > 0; i--) {
            right[i] = max(right[i + 1] + nums[i - 1], nums[i - 1]);
            right[i] = max(right[i + 1], right[i]);
        }
        
        int result = INT_MIN;
        for (int i = 1; i < n; i++) {
            total[i] = left[i] + right[i + 1];
            result = max(total[i], result);
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

