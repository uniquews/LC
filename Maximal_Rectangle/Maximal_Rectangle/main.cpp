//
//  main.cpp
//  Maximal_Rectangle
//
//  Created by Shuai Wang on 6/26/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    int maximalRectangle(vector<vector<char> > &matrix) {
        
        if(matrix.empty()) return 0;
        int row = (int)matrix.size();
        int col = (int)matrix[0].size();
        vector<int> H(col, 0);
        vector<int> L(col, 0);
        vector<int> R(col, col);
        int ret = 0;
        
        for(int i = 0; i<row; i++){
            int left =0; int right = col;
            // calculate left(i, j)
            for(int j = 0; j<col; j++){
                if(matrix[i][j] == '1'){
                    H[j]++;
                    L[j] = max(L[j], left);
                    
                }else{
                    H[j] = 0;
                    left = j+1;
                    L[j] = 0;
                    R[j] = col;
                }
                
                
            }
            
            for(int j=col-1; j>=0; j--){
                
                if(matrix[i][j] == '1'){
                    R[j] = min(R[j], right);
                    ret = max(ret, H[j]*(R[j]-L[j]));
                    
                }else{
                    
                    right = j;
                }
            }
        }
        return ret;
    }
    
};



int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    vector<vector<char>> matrix = {{'0'}};
    cout << s.maximalRectangle(matrix);
    return 0;
}

