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
//class Solution {
//public:
//    int uniquePaths(int m, int n) {
//        vector<vector<int>> f;
//        f.resize(m, vector<int>(n,0));
//        for(int i=0; i<n; i++){
//            f[0][i] =1;
//        
//        }
//        
//        for(int i=0; i<m; i++){
//            f[i][0] =1;
//        }
//        
//        for(int i=1; i<m; i++){
//            for(int j =1; j<n;j++){
//                f[i][j] = f[i-1][j] + f[i][j-1];
//            }
//        }
//        
//        return f[m-1][n-1];
//    }
        

        
//1D array dynamic programming
//        vector<int> f;
//        f.resize(n, 0);
//        f[0]=1;
//        for(int i=0; i<m; i++){
//            for(int j =1; j<n;j++)
//                f[j] = f[j-1]+f[j];
//        
//        }
//        
//        return f[n-1];
        
        
        
        
// Memoization = dfs+cache
//       vector<vector<int>> f;
//       f.resize(m+1, vector<int>(n+1,0));
//       return dfs(m,n, f);
//        
//    }
//    
//    
//    int dfs(int m, int n, vector<vector<int>> &f){
//        
//        if(m==0 && n==0) return 0;
//        if(m==1 && n==1){
//            f[m][n] = 1;
//            return f[m][n];
//        }
//        
//        
//        if(m ==1){
//            if(f[m][n]>0)
//                return f[m][n];
//            else{
//                f[m][n] =dfs(1, n-1, f);
//                return f[m][n];
//            }
//            
//        
//        }
//        
//        if(n == 1){
//            if(f[m][n]>0)
//                return f[m][n];
//            else{
//                f[m][n] = dfs(m-1, 1, f);
//                return f[m][n];
//            }
//        
//        }
//        
//        if(f[m][n]>0) return f[m][n];
//        else{
//            f[m][n] =dfs(m-1, n, f) + dfs(m, n-1, f);
//            return f[m][n];
//        }
// 
//    
//    }
//};


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int> (n, 0));
        f[0][0] = 1;
        for (int column = 1; column < n; column++) {
            f[0][column] = f[0][column - 1];
        }
        
        for (int row = 1; row < m; row++) {
            f[row][0] = f[row - 1][0];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        
        return f[m - 1][n - 1];
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

