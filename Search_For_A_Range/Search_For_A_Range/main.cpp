//
//  main.cpp
//  Search_For_A_Range
//
//  Created by Shuai Wang on 7/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;

//class Solution {
//public:
//    vector<int> searchRange(int A[], int n, int target) {
//        vector<int> result;
//        
//        int first = 0;
//        int end = n - 1;
//        // search for lower bound
//        while (first + 1 < end) {
//            int mid = (first + end) / 2;
//            if(A[mid] < target) {
//                first = mid;
//            } else {
//                end = mid;
//            }
//        }
//        
//        if (A[first] == target) { // [2,2] we don't go into while loop, so we need to check A[first]
//            result.push_back(first);
//        }else if (A[end] == target) { // secondly check A[end] because when A[mid] = target, we move end = mid
//            result.push_back(end);
//        } else {
//            result.push_back(-1);
//        }
//        
//        
//        //search for upper bound
//        first = 0;
//        end = n - 1;
//        
//        while(first + 1 < end) {
//            int mid = (first + end) / 2;
//            if (A[mid] > target) {
//                end = mid;
//            } else {
//                first = mid;
//            }
//        }
//        
//        if (A[end] == target) { // same as [2,2]
//            result.push_back(end);
//        } else if (A[first] == target) {
//            result.push_back(first);
//        } else {
//            result.push_back(-1);
//        }
//        
//        return result;
//    }
//    
//};


class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // search for upper bound
        
        int upper = 0;
        int lower = 0;
        
        int start = 0;
        int end = n - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (target == A[mid]) {
                start = mid;
            } else if (target < A[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if (A[start] == target) {
            if (A[end] == target) {
                upper = end;
            } else {
                upper = start;
            }
        } else {
            if (A[end] == target) {
                upper = end;
            } else {
                upper = -1;
            }
        }
        
        // search for lower bound
        start = 0;
        end = n - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (target == A[mid]) {
                end = mid;
            } else if (target < A[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if (A[start] == target) {
            lower = start;
        } else {
            if (A[end] == target) {
                lower = end;
            } else {
                lower = -1;
            }
        }
        
        
        vector<int> result;
        result.push_back(lower);
        result.push_back(upper);
        
        return result;
        
    }
};



int main(int argc, const char * argv[])
{
  
    int A[] = {5, 7, 7, 8, 8, 10};
    Solution su;
    vector<int> result = su.searchRange(A, 6, 8);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}

