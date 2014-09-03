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
        // i ... j sum is equal to sum[j] - sum[i - 1]
        
        vector<int> sum(n, 0);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                sum[0] = A[0];
            } else {
                sum[i] = sum[i - 1] + A[i];
            }
        }
        
        int result = sum[0]; // not like stock, you have to pick at least one as result
        int valley = 0; // sum[j] - sum [0] is 1 ....j. In order to get sum[0], valley shoule be 0 at the beginning
        for (int i = 0; i < sum.size(); i++) {
            result = max(result, sum[i] - valley);
            valley = min(valley, sum[i]);
        }
        
        return result;
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    int A[9] = {-2 ,1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    cout << s.maxSubArray(A, 9) << endl;
    
    return 0;
}

