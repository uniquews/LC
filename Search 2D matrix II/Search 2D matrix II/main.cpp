//
//  main.cpp
//  Search 2D matrix II
//
//  Created by Shuai Wang on 9/26/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

// get the target occurrence

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int searchMatrix(vector<vector<int>> &matrix, int target){
        if (matrix.size() == 0) {
            return 0;
        }
        
        
        int row = (int)matrix.size();
        int column = (int)matrix[0].size();
        
        
        if (target < matrix[0][0] || target > matrix[row - 1][column - 1]) {
            return 0;
        }
        
        int result = 0;
        int i = row - 1;
        int j = 0;
        while (i >= 0 && j <= column - 1) {
            if (matrix[i][j] > target) {
                i--;
            } else if (matrix[i][j] < target) {
                j++;
            } else {
                i--;
                j++;
                result++;
            }
        }
        
        return result;
    }


};

int main(int argc, const char * argv[])
{

    vector<vector<int>> matrix = {{1,4,7,12,13},
                                {2,5,8,13,19},
                                {3,6,9,16,22},
                                {10,13,14,17,24},
                                {18,21,23,26,30}};
    Solution su;
    cout << su.searchMatrix(matrix, 13) << endl;
    return 0;
}

