//
//  main.cpp
//  Remove_Element
//
//  Created by Shuai Wang on 7/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n == 0) return 0;
        
        int cur = 0;
        for(int i=0; i < n; i++){
            if(A[i]!=elem)
                A[cur++] = A[i];
        }
        return cur;
    }
};


int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

