//
//  main.cpp
//  Maximal_Rectangle
//
//  Created by Shuai Wang on 6/26/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int row = (int)matrix.size();
        int column = (int)matrix[0].size();
        int result = INT_MIN;
        vector<vector<int>> height(row, vector<int>(column, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (matrix[i][j] == '0') {
                    height[i][j] = 0;
                } else {
                    height[i][j] = i == 0 ? 1 : height[i - 1][j] + 1;
                }
            }
        }
        
        for (int i = 0; i < row; i++) {
            int area = largestRectangleArea(height[i]);
            if (area > result) {
                result = area;
            }
        }
        
        return result;
    }
    
    
    int largestRectangleArea(vector<int> &height) {
        int result = 0;
        stack<int> stk;
        for (int i = 0; i <= (int)height.size(); i++) {
            int cur = i != height.size() ? height[i] : -1;
            while (stk.size() != 0 && cur < height[stk.top()]) {
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


    Solution s;
    vector<vector<char>> matrix = {{'0'}, {'1'}};
    cout << s.maximalRectangle(matrix);
    return 0;
}

