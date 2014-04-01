//
//  main.cpp
//  RemoveDuplicatesfromSortedArrayII
//
//  Created by Shuai Wang on 3/31/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=2) return n;
        int cur=1;
        for(int i=2; i<n;i++){
            if(!(A[cur]==A[i]&& A[cur]==A[cur-1]))
                A[++cur]=A[i];
        }
        return cur+1;
    }
};
int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

