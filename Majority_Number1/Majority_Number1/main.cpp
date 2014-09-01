//
//  main.cpp
//  Majority_Number1
//
//  Created by Shuai Wang on 8/31/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {

public:
    
    int majorityNumber(int A[], int n) {
        int candidate = 0, count = 0;
        
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                candidate = A[i];
                count++;
            } else {
                if (candidate == A[i]) {
                    count++;
                } else{
                    count--;
                }
            }
        }
        
        return candidate;
    }

};

int main(int argc, const char * argv[])
{

    int A[] = {1,1,1,1,2,2};
    Solution su;
    cout << su.majorityNumber(A, 6) << endl;
    return 0;
}

