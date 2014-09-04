//
//  main.cpp
//  Minimun_Subarray
//
//  Created by Shuai Wang on 9/3/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    
    int minSubArray(vector<int> A) {
        int result = INT_MIN;
        vector<int> _max(A.size());
        for (int i = 0; i < A.size(); i++) {
            A[i] = A[i] * (-1);
        }
        
        int prevSum = 0;
        vector<int> sum (A.size());
        for (int i = 0; i < A.size(); i++) {
            sum[i] = prevSum + A[i];
            prevSum = sum[i];
        }
        
        
        int peek = (int)sum[A.size() - 1];
        _max[0] = sum[0];
        for (int i = (int)sum.size() - 2; i >=0; i--) {
            _max[i + 1] = peek - sum[i];
            peek = max(peek, sum[i]);
            result = max(result, _max[i + 1]);
        }
        
        return result * (-1);
    }

};

int main(int argc, const char * argv[])
{

    Solution su;
    vector<int> A = {1, -1, -2, 1};
    cout << su.minSubArray(A) << endl;
    return 0;
}

