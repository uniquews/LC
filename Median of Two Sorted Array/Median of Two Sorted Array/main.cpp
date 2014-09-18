//
//  main.cpp
//  Median of Two Sorted Array
//
//  Created by Shuai Wang on 9/17/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int num = m + n;
        if (num % 2 == 0) {
            return (findMed(A, m, B, n, num / 2) + findMed(A, m, B, n, num / 2 + 1)) / 2;
        } else {
            return findMed(A, m, B, n, num / 2 + 1);
        }
    }
    
    double findMed(int A[], int m, int B[], int n, int k) {
        if (m > n) {
            return findMed(B, n, A, m, k);
        }
        
        if (m == 0) {
            return B[k - 1];
        }
        
        if (k == 1) {
            return min(A[0], B[0]);
        }
        
        int pos = min(k / 2, m);
        
        int posInB = k - pos;
        if (A[pos - 1] < B[posInB - 1]) {
            return findMed(A + pos, m - pos, B, n, k - pos);
        } else if (A[pos - 1] > B[posInB - 1]) {
            return findMed(A, m, B + posInB, n - posInB, k - posInB);
        } else {
            return A[pos - 1];
        }
        
        
    }
    
    
    
};

int main(int argc, const char * argv[])
{

    Solution su;
    int A[] = {1,2};
    int B[] = {1,2};
    int m = 2;
    int n = 2;
    su.findMedianSortedArrays(A, 2, B, n);
    return 0;
}

