//
//  main.cpp
//  Unique_Path2
//
//  Created by Shuai Wang on 6/20/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        
        vector<vector<int>> f (row, vector<int> (column, 0));
        if (obstacleGrid[0][0] == 1) {
            f[0][0] = 0;
            return 0;
        } else {
            f[0][0] = 1;
        }
        
        for (int i = 1; i < obstacleGrid[0].size(); i++) {
            if (obstacleGrid[0][i] == 0) {
                f[0][i] = f[0][i - 1];
            } else {
                f[0][i] = 0;
            }
        }
        
        for (int i = 1; i < obstacleGrid.size(); i++) {
            if (obstacleGrid[i][0] == 0) {
                f[i][0] = f[i - 1][0];
            } else {
                f[i][0] = 0;
            }
        }
        
        
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < column; j++) {
                if (obstacleGrid[i][j] == 0) {
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                } else {
                    f[i][j] = 0;
                }
            }
        }
        
        return f[row - 1][column - 1];
    }
};


int main(int argc, const char * argv[])
{

//    vector<vector<int>> obstacleGrid = {{0,1,0,0,0}, {1,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};
    vector<vector<int>> obstacleGrid = {{0,0}};
    Solution s;
    cout <<  s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}

