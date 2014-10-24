//
//  main.cpp
//  Search in Rotated Array 2
//
//  Created by Shuai Wang on 9/17/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

//class Solution {
//public:
//    bool search(int A[], int n, int target) {
//        int start = 0;
//        int end = n - 1;
//        
//        while (start + 1 < end) {
//            int mid = start + (end - start) / 2;
//            if (A[mid] == target) {
//                return true;
//            }
//            
//            if (A[start] < A[mid]) {
//                if (A[start] <= target && target < A[mid]) {
//                    end = mid;
//                } else {
//                    start = mid;
//                }
//            } else if (A[start] > A[mid]) {
//                if (A[mid] < target && target <= A[end]) {
//                    start = mid;
//                } else {
//                    end = mid;
//                }
//            } else {
//                start++;
//            }
//        }
//        
//        
//        if (A[start] == target) {
//            return true;
//        }
//        
//        if (A[end] == target) {
//            return true;
//        }
//        
//        return false;
//    }
//};

class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n == 0) {
            return false;
        }
        
        int start = 0;
        int end = n - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                return true;
            }
            
            if (A[start] < A[mid]) {
                if (A[start] <= target && target < A[mid]) {
                    end = mid;
                } else {
                    start = mid;
                }
            } else if (A[start] > A[mid]) {
                if (A[mid] < target && target <= A[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
            } else {
                start++;
            }
        }
        
        if (A[start] == target) {
            return true;
        }
        
        if (A[end] == target) {
            return true;
        }
        
        return false;
    }
};
int main(int argc, const char * argv[])
{

    int A[] = {1};
    int target = 0;
    Solution su;
    cout << su.search(A, 1, target) <<endl;
    return 0;
}

