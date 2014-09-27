//
//  main.cpp
//  First_Missing_Positive
//
//  Created by Shuai Wang on 7/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;


class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (n == 0) {
            return 1;
        }
        
        for (int i = 0; i < n; i++) {
            while (A[i] != i + 1) {
                if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1]) {
                    break;
                }
                
                swap(A[i], A[A[i] - 1]);
            }
        }
        
        
        for (int i = 0; i < n; i++) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
    
};


int main(int argc, const char * argv[])
{

    int A[] = {1};
    Solution su;
    su.firstMissingPositive(A, 1);
    return 0;
}

