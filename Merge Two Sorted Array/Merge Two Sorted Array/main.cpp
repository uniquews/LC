//
//  main.cpp
//  Merge Two Sorted Array
//
//  Created by Shuai Wang on 9/27/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

//class Solution {
//public:
//    void merge(int A[], int m, int B[], int n) {
//        int i = m - 1;
//        int j = n - 1;
//        while (i >= 0 && j >= 0) {
//            A[i + j + 1] = (A[i] > B[j] ? A[i--] : B[j--]);
//        }
//        
//        while (j >= 0) {
//            A[j] = B[j];
//            j--;
//        }
//        
//        return;
//    }
//};

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int index = m + n - 1;
        int p = m - 1;
        int q = n - 1;
        while (p >= 0 && q >= 0) {
            if (A[p] >= A[q]) {
                A[index--] = A[p--];
            } else {
                A[index--] = A[q--];
            }
        }
        
        while (q >= 0) {
            A[index--] = B[q--];
        }
        
        return;
    }
};

int main(int argc, const char * argv[])
{

    int A[] = {};
    int B[] = {1};
    
    Solution su;
    su.merge(A, 0, B, 1);
    return 0;
}

