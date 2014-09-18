//
//  main.cpp
//  RemoveDuplicateNumberInArray
//
//  Created by Shuai Wang on 3/31/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;


class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        
        int cur = 0;
        for (int i = 1; i < n; i++) {
            if (A[cur] != A[i]) {
                A[++cur] = A[i];
            }
        }
        
        return cur + 1;
        
        
    }
    
};


int main(int argc, const char * argv[])
{

    int A[ ] = {1,1,2};
    int n = 3;
    Solution su;
    cout << su.removeDuplicates(A, n) << endl;
    return 0;
}

