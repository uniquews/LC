//
//  main.cpp
//  Largest_Rectangle_In_Histogram
//
//  Created by Shuai Wang on 7/9/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int largestRectangleArea(vector<int> &height) {
//        if (height.size() == 0) {
//            return 0;
//        }
//        
//        int result = 0;
//        stack<int> stk;
//        for (int i = 0; i <= height.size(); i++) {
//            int cur = i == height.size() ? -1 : height[i];
//            while (stk.size() != 0 && cur < height[stk.top()]) {
//                int h = height[stk.top()];
//                stk.pop();
//                
//                int w = 0;
//                if (stk.size() == 0) {
//                    w = i; // 这个递增序列的前面有i个，递增序列的结尾是i - 1，被i弹出
//                } else {
//                    w = i - stk.top() - 1;
//                }
//                
//                
//                result = max(result, h * w);
//                
//            }
//            
//            stk.push(i);
//        }
//        
//        return result;
//    }
//};

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.size() == 0) {
            return  0;
        }
        
        int n = height.size();
        int area = 0;
        vector<int> left(height.size(), 0);
        vector<int> right(height.size(), 0);
        vector<int> result(height.size(), 0);
        
        left[0] = 0;
        for (int i = 1; i < left.size(); i++) {
            if (height[i] <= height[i - 1]) {
                left[i] = left[i - 1];
            } else {
                left[i] = i;
            }
        }
        
        right[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (height[i] > height[i + 1]) {
                right[i] = i;
            } else {
                right[i] = right[i + 1];
            }
        }
        
        for (int i = 0; i < n; i++) {
            result[i] = (left[i] - right[i] + 1) * height[i];
            area = max(result[i], area);
        }
        return area;
        
    }
};



int main(int argc, const char * argv[])
{

//    vector<int> h = {100, 1000, 8};
    vector<int> h = {2,1,5,6,2,3};
    Solution su;
    cout << su.largestRectangleArea(h) << endl;
    return 0;
}

