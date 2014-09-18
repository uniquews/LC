//
//  main.cpp
//  SetMatrixZero
//
//  Created by Shuai Wang on 3/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        
        bool firstRow = false;
        bool firstColumn = false;
        
        for (int i = 0; i < column; i++) {
            if (matrix[0][i] == 0) {
                firstRow = true;
                break;
            }
        }
        
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                firstColumn = true;
                break;
            }
        }
        
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < column; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for (int i = 1; i < column; i++) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < row; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        
        for (int i = 1; i < row; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < column; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (firstRow == true) {
            for (int i = 0; i < column; i++) {
                matrix[0][i] = 0;
            }
        }
        
        if (firstColumn == true) {
            for (int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
        
        return;
    }
    
};


int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

