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
        
        int m = (int)obstacleGrid.size();
        int n =(int)obstacleGrid[0].size();
        
        for(int i=0; i<m; i++){
            for(int j =0; j<n; j++){
                if(obstacleGrid[i][j]==1)
                    obstacleGrid[i][j] = INT_MIN;
            }
        }
        
        if(obstacleGrid[0][0] == 0){
            obstacleGrid[0][0] = 1;
        }
        

            for(int i=1; i<n; i++){
                if(obstacleGrid[0][i]!=INT_MIN && obstacleGrid[0][i-1]!=INT_MIN)
                    obstacleGrid[0][i] = obstacleGrid[0][i-1];
               }
        
            for(int i=1; i<m; i++){
                if(obstacleGrid[i][0]!=INT_MIN && obstacleGrid[i-1][0]!=INT_MIN)
                    obstacleGrid[i][0] =obstacleGrid[i-1][0];
            }
        
            for(int i=1; i<m; i++){
                for(int j =1; j<n;j++){
                    if(obstacleGrid[i][j]!=INT_MIN){
                        if(obstacleGrid[i-1][j]!=INT_MIN && obstacleGrid[i][j-1]!=INT_MIN)
                            obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                        else if(obstacleGrid[i-1][j]!=INT_MIN && obstacleGrid[i][j-1]==INT_MIN){
                            obstacleGrid[i][j] = obstacleGrid[i-1][j];
                        }else if(obstacleGrid[i-1][j]==INT_MIN && obstacleGrid[i][j-1]!=INT_MIN){
                            obstacleGrid[i][j] = obstacleGrid[i][j-1];
                        }
                    }
                    
                }
            }
        
        for(int i=0 ;i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == INT_MIN)
                    obstacleGrid[i][j] = 0;
                
            
            }
        }
        
        
               return obstacleGrid[m-1][n-1];
        
    }
};



int main(int argc, const char * argv[])
{

    vector<vector<int>> obstacleGrid = {{0,1,0,0,0}, {1,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};
    Solution s;
    cout <<  s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}

