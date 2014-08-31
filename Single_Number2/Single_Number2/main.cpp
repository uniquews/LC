//
//  main.cpp
//  Single_Number2
//
//  Created by Shuai Wang on 8/31/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int singleNumber(int A[], int n) {
        
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int count  = 0;
            for (int j = 0; j < n; j++) {
                count += ((A[j] >> i) & 1);
            }
            
            result |= (count % 3) << i;
        }
        
        return result;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

