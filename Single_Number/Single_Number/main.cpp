//
//  main.cpp
//  SIngle_Number
//
//  Created by Shuai Wang on 8/31/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        
        if (n == 1) {
            return A[0];
        }
        
        int tmp = A[0] ^ A[1];
        
        for (int i = 2; i < n - 1; i++) {
            tmp = A[i] ^ tmp;
        }
        
        return tmp;
    }
};

int main(int argc, const char * argv[])
{

    
    int A[] = {2,2,1};
    Solution su;
    cout << su.singleNumber(A, 3) << endl;
    return 0;
}

