//
//  main.cpp
//  Minimum_Path_Sum
//
//  Created by Shuai Wang on 6/28/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int row = (int)grid.size();
        int col = (int)grid[0].size();
        
        return dp(row, col, grid);
    }
    
    int dp(int row, int col, vector<vector<int>> &grid){
        vector<vector<int>> f(row, vector<int> (col, 0));
        f[0][0] = grid[0][0];
        
        for(int i =1; i< col; i++){
            f[0][i] = f[0][i-1]+grid[0][i];
        }
        
        for(int i=1; i< row; i++){
            f[i][0] = f[i-1][0] + grid[i][0];
        }
        
        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
            
            }
        
        }
        
        return f[row-1][col-1];
    
    }
};




int main(int argc, const char * argv[])
{

    vector<vector<int>> grid = {{1,2}, {1,1}};
    Solution s;
    cout << s.minPathSum(grid) << endl;
    return 0;
}

