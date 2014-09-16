//
//  main.cpp
//  Search_Insert_Position
//
//  Created by Shuai Wang on 7/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;



// Using template
//class Solution {
//public:
//    int searchInsert(int A[], int n, int target) {
//        if (n == 0) {
//            return -1;
//        }
//        
//        int first = 0;
//        int end = n - 1;
//        while (first + 1 < end) {
//            int mid = first + (end - first) / 2;
//            if (A[mid] == target) {
//                return mid;
//            } else if (A[mid] > target) {
//                end = mid;
//            } else {
//                first = mid;
//            }
//        }
//        
//        if (A[first] == target) {
//            return first;
//        } else if (A[end] == target) {
//            return end;
//        } else if (A[end] < target) {
//            return end + 1;
//        } else if (A[first] > target) {
//            return first + 1;
//        } else {
//            return first + 1;
//        }
//        
//    }
//};

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int upper = 0;
        int lower = 0;
        int start = 0;
        int end = n - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] < target) {
                start = mid;
            } else{
                end = mid;
            }
        }
        
        if (A[start] == target) {
            return start;
        }
        
        if (A[end] == target) {
            return end;
        }
        
        if (A[start] < target && A[end] > target) {
            return start + 1;
        }
        
        if (A[start] > target) {
            return start;
        }
        
        if (A[end] < target) {
            return end + 1;
        }
        
        return  -1;
    }
};

int main(int argc, const char * argv[])
{

    int A[] = {1,3,5,6};
    int target = 0;
    Solution su;
    cout << su.searchInsert(A, 4, target) << endl;
    return 0;
}

