//
//  main.cpp
//  Rotate_Image
//
//  Created by Shuai Wang on 7/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int size = matrix.size();
        
        for(int i=0; i<size;i++){
            for(int j = 0; j< size-i; j++){
                
                swap(matrix[i][j], matrix[size-1-j][size-1-i]);
            }
        }
        
        for(int i = 0; i< size/2; i++){
            for(int j=0; j<size; j++){
                swap(matrix[i][j], matrix[size-1-i][j]);
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

