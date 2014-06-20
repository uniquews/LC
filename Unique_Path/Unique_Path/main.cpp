//
//  main.cpp
//  Unique_Path
//
//  Created by Shuai Wang on 6/20/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


//2D array dynamic programming
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f;
        f.resize(m, vector<int>(n,0));
        for(int i=0; i<n; i++){
            f[0][i] =1;
        
        }
        
        for(int i=0; i<m; i++){
            f[i][0] =1;
        }
        
        for(int i=1; i<m; i++){
            for(int j =1; j<n;j++){
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
        
        return f[m-1][n-1];
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    int m = 1;
    int n = 2;
    Solution s;
    cout << s.uniquePaths(m, n);
    vector<vector<int>> f;
//    f.resize(m, vector<int>(n,1));
//    cout << f.a <<endl;

    return 0;
}

