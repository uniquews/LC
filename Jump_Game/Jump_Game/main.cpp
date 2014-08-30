//
//  main.cpp
//  Jump_Game
//
//  Created by Shuai Wang on 7/9/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        vector<bool> table(n);
        table[0] = true;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (table[j] && A[j] + j >= i) {
                    table[i] = true;
                    break;
                }
            }
        }
        
        return table[n - 1];
    }
    
};

int main(int argc, const char * argv[])
{

    int A[] = {0,1};
    Solution su;
    su.canJump(A, 2);
    return 0;
}

