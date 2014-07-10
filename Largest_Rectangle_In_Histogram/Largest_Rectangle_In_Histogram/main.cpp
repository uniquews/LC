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

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> stk;
        height.push_back(0); // for {1}
        int sum =0;
        for(int i=0; i<height.size(); i++){
            if(stk.empty() || height[i] > height[stk.top()]){
                stk.push(i); // keep track of taller one
            }else{
                int tempTallestIndex = stk.top(); // so far the tallest one
                stk.pop();
                sum = max(sum, height[tempTallestIndex]*(stk.empty()?i:i-stk.top()-1));
                i--;
            }
        }
        
        return sum;
    }
};




int main(int argc, const char * argv[])
{

    vector<int> h = {1};
    Solution su;
    su.largestRectangleArea(h);
    return 0;
}

