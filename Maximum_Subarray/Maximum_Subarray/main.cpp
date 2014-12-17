//
//  main.cpp
//  Maximum_Subarray
//
//  Created by Shuai Wang on 6/25/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxSubArray(int A[], int n) {
        vector<int> f(n);
        f[0] = A[0];
        int result = f[0];
        for (int i = 1; i < n; i++) {
            f[i] = max(f[i - 1] + A[i], A[i]);
            result = max(result, f[i]);
        }
        
        return result;
        
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
//    int A[9] = {-2 ,1, -3, 4, -1, 2, 1, -5, 4};
    int A[] = {-2, 1};
    Solution s;
    cout << s.maxSubArray(A, 2) << endl;
    
    return 0;
}

