//
//  main.cpp
//  Maximum_Subarray_Difference
//
//  Created by Shuai Wang on 9/3/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    int maxDiffer(vector<int> A) {
        if (A.size() == 0) {
            return 0;
        }
        
        int prevSum = 0;
        vector<int> sum(A.size());
        for (int i = 0; i < A.size(); i++) {
            sum[i] = prevSum + A[i];
            prevSum  = sum[i];
        }
        
        // from the left ro right, find the maximun than minimum
        int valley = 0;
        vector<int> leftMax(A.size());
        leftMax[0] = sum[0];
        for (int i = 1; i < A.size(); i++) {
            leftMax[i] = max(sum[i], sum[i] - valley);
            valley = min(valley, sum[i]);
        }
        
        vector<int> minorA(A.size());
        
        for (int i = 0; i < A.size(); i++) {
            minorA[i] = A[i] * (-1);
        }
        
        vector<int> minorSum(A.size());
        int prevMinorSum = 0;
        for (int i = 0; i < A.size(); i++) {
            minorSum[i] = prevMinorSum + A[i];
            prevMinorSum = minorSum[i];
        }
        
        int peek = minorSum[A.size() - 1];
        vector<int>rightMin(A.size());
        rightMin[A.size() - 1] = minorSum[A.size() - 1];
        for (int i = (int)A.size() - 2; i >= 0; i++) {
            rightMin[i] = max(leftMax[i], leftMax[i] + peek - rightMin[])
        }
        
    
    }

    

};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

