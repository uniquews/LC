//
//  main.cpp
//  Find_Peak
//
//  Created by Shuai Wang on 8/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//
//public:
//    
//    int findPeak(vector<int> &nums) {
//    
//        if (nums.size() == 0) {
//            return -1;
//        }
//        
//        int first = 0;
//        int last = (int)(nums.size() - 1);
//        
//        while (first + 1 < last) {
//            int mid = (first + last) / 2;
//
//            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
//                return mid;
//            }
//            
//            if (nums[mid - 1] >=  nums[mid]) {
//                last = mid;
//                continue;
//            }
//            
//            if (nums[mid + 1] > nums[mid]) {
//                first = mid;
//                continue;
//            }
//        }
//        
//        if (nums[first] >= nums[last]) {
//            return first;
//        }
//        
//        if (nums[first] < nums[last]) {
//            return last;
//        }
//        
//        return -1;
//        
//    }
//
//    
//};

class Solution {
public:
    int findPeak(vector<int> &A) {
        if (A.size() == 0) {
            return -1;
        }
        
        int start = 0;
        int end = (int)A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (mid + 1 < A.size() && mid - 1 >= 0 && A[mid] > A[mid + 1] && A[mid] > A[mid - 1]) {
                return mid;
            } else if (mid + 1 < A.size() && A[mid - 1] < A[mid] && A[mid] < A[mid + 1]) {
                start = mid;
            } else if (mid - 1 >= 0 && A[mid] < A[mid - 1] && A[mid + 1] < A[mid]) {
                end = mid;
            } else {
                start++;
            }
            
        }
        
        if (start == end) {
            return start;
        }
        
        if (A[start] > A[end]) {
            return start;
        }
        
        if (A[end] > A[start]) {
            return end;
        }
        
        return -1;
        
    }
    
};

int main(int argc, const char * argv[])
{

//    vector<int> nums = {10, 20, 30, 40, 50};
//    vector<int> nums = { 100, 80, 60, 50, 20};
//    vector<int> nums = {20,20,20,20};
    vector<int> nums = {10, 20, 15, 2, 23, 90, 67};
//    vector<int> nums = {5, 10, 20, 15};
    
    Solution su;
    cout << su.findPeak(nums) << endl;
    return 0;
}

