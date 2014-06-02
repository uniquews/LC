//
//  main.cpp
//  Spiral Matrix
//
//  Created by Shuai Wang on 6/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        
        int m = (int)matrix.size();  // row
        if(m==0)return vector<int>();
        int n = (int)matrix[0].size(); //column
        if(n==0)return vector<int>();
        
        vector<int> result(m*n, 0);
        int layer;
        int index=0;
        
        for(layer=min(m,n); layer>1; layer-=2){
            int offset = (min(m,n) - layer)/2;
            
            // left to right
            for(int i=offset; i<n-offset-1; i++){
                result[index++] = matrix[offset][i];
            }
            
            //top to bottom
            for(int i=offset; i<m-offset-1; i++){
                result[index++]= matrix[i][n-offset-1];
            }
            
            //right to left
            for(int i=n-offset-1; i>offset; i--){
                result[index++]=matrix[m-offset-1][i];
            }
            
            //bottom to top
            for(int i=m-offset-1; i>offset; i--){
                result[index++] = matrix[i][offset];
            }
        }
        
        
        if(layer==1){
            
            if(m>n){
                for(int i=n/2; i<m-n/2; i++){
                    result[index++]=matrix[i][n/2];
                }
            }else{
                for(int i=m/2; i<n-m/2; i++){
                    result[index++] = matrix[m/2][i];
                }
            }
        }
        
        return result;
        
    }
    
    
};

int main(int argc, const char * argv[])
{



    return 0;
}

