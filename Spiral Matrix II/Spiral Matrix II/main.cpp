//
//  main.cpp
//  Spiral Matrix II
//
//  Created by Shuai Wang on 6/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if(n==0) return vector<vector<int>> ();
        
        vector<vector<int>>result (n, vector<int>(n,0));
        
        int inputNum = 1;
        int layer = n;
        for(; layer>1; layer-=2){
            int offset = (n-layer)/2;
            //from left to right
            for(int i=offset; i<n-offset-1; i++){
                result[offset][i]=inputNum++;
            }
            
            //from top to down
            for(int i=offset; i< n-offset-1; i++){
                result[i][n-offset-1]=inputNum++;
            }
            
            //from right to left
            for(int i=n-offset-1; i>offset; i--){
                result[n-offset-1][i]=inputNum++;
            }
            
            
            for(int i=n-offset-1; i>offset; i--){
                result[i][offset]=inputNum++;
            }
        }
        
        
        if(layer==1){
            result[n/2][n/2]=inputNum++;
        }
        
        return result;
    }
};

int main(int argc, const char * argv[])
{

    
    
    return 0;
}

