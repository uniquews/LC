//
//  main.cpp
//  Jump_Game
//
//  Created by Shuai Wang on 7/9/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool canJump(int A[], int n) {
        
        int rightMost = 0;
        for(int start = 0; start <=rightMost; start++){
            if(rightMost < start + A[start])
                rightMost = start + A[start];
            if(rightMost >= n-1)
                return true;
        }
        
        return false;
    }
};

int main(int argc, const char * argv[])
{

    int A[] = {0,1};
    Solution su;
    su.canJump(A, 2);
    return 0;
}

