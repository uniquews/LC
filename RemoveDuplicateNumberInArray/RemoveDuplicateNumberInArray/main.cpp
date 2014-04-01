//
//  main.cpp
//  RemoveDuplicateNumberInArray
//
//  Created by Shuai Wang on 3/31/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0) return 0;
        int i=1;
        int j=0;
        for(;i<n;i++){
            if(A[i]==A[i-1])
                continue;
            else
                A[++j]=A[i];
        }
        return j+1;
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

