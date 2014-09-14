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
        int prev = 0;
        vector<int> sum(n);
        for (int i = 0; i < n; i++) {
            prev = prev + A[i];
            sum[i] = prev;
        }
        
        int _min = 0;
        int result = INT_MIN;
        for (int i = 0; i < sum.size(); i++) {
            result = max(result, sum[i] - _min);
            
            _min = min(_min, sum[i]);
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

