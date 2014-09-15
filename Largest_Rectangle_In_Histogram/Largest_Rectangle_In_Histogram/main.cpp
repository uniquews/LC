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
//        stack<int> stk;
//        int result = 0;
//        for (int i = 0; i <= height.size(); i++) {
//            int curt = i == height.size() ? -1 : height[i];
//            while (stk.size() != 0 && curt < height[stk.top()]) {
//
//                int h = height[stk.top()];
//                stk.pop();
//                
//                int w = 0;
//                if (stk.size() == 0) {
//                    w = i;
//                } else {
//                    w = i - stk.top() - 1;
//                }
//                result = max(result, h * w);
//                
//            }
//            
//            stk.push(i);
//        }
//        
//        return result;
//    }
//    
//};

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.size() == 0) {
            return 0;
        }
        
        
        stack<int> stk;
        int result = 0;
        for (int i = 0; i <= height.size(); i++) {
            int cur = i == height.size() ? -1 : height[i];
            while (stk.size() != 0 && cur < stk.top()) {
                int h = height[stk.top()];
                stk.pop();
                int w = 0;
                if (stk.size() == 0) {
                    w = i;
                } else {
                    w = i - stk.top() - 1;
                }
                
                result = max(result, h * w);
            }
            
            stk.push(i);
        }
        
        return result;
    }
};




int main(int argc, const char * argv[])
{

//    vector<int> h = {8, 4};
    vector<int> h = {0};
    Solution su;
    su.largestRectangleArea(h);
    return 0;
}

