//
//  main.cpp
//  Single_Number
//
//  Created by Shuai Wang on 7/3/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int singleNumber(int A[], int n) {
        int temp = A[0];
        for(size_t i = 1; i<n; i++){
            temp = temp ^ A[i];
        }
        
        return temp;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

