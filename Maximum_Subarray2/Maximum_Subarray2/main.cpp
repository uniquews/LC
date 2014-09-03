//
//  main.cpp
//  Maximum_Subarray2
//
//  Created by Shuai Wang on 9/3/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> A) {
        if (A.size() == 0) {
            return 0;
        }
        
        int result = INT_MIN;
        int prevSum = 0;
        vector<int> sum(A.size(), 0);
        for (int i = 0; i < A.size(); i++) {
            sum[i] = prevSum + A[i];
            prevSum = sum[i];
        }
        
        vector<int> maxLeft(A.size());
        int valley = sum[0];

        for (int i = 1; i < A.size(); i++) {
            maxLeft[i] = sum[i] - valley;
            valley = min (sum[i], valley);
        }
        
        int peek = sum[A.size() - 1];
        vector<int> maxRight (A.size());
        for (int i = (int)A.size() - 1; i >= 0; i--) {
            maxRight[i] = max(maxLeft[i] + peek - sum[i], maxLeft[i]);
            peek = max(peek, sum[i]);
            result = max(result, maxRight[i]);

            
        }
        
        
        return result;
        
        
    }


};

int main(int argc, const char * argv[])
{

    Solution su;
    vector<int> A = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << su.maxSubArray(A) << endl;
    return 0;
}

