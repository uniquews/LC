//
//  main.cpp
//  Single_Number2
//
//  Created by Shuai Wang on 8/31/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
        
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int count  = 0;
            for (int j = 0; j < n; j++) {
                count += ((A[j] >> i) & 1); // count 只有可能是0或1，所以后面不会进位
            }
            
            
            result += (count % 3) << i;
        }
        
        return result;
    }
};

int main(int argc, const char * argv[])
{

    int A[] = {0,0,0,1};
    Solution su;
    cout << su.singleNumber(A, 4) << endl;
    return 0;
}

