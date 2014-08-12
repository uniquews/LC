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

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        
        int first = 0;
        int end = n - 1;
        // search for lower bound
        while (first + 1 < end) {
            int mid = (first + end) / 2;
            if(A[mid] < target) {
                first = mid;
            } else {
                end = mid;
            }
        }
        
        if (A[first] == target) { // [2,2] we don't go into while loop, so we need to check A[first]
            result.push_back(first);
        }else if (A[end] == target) { // secondly check A[end] because when A[mid] = target, we move end = mid
            result.push_back(end);
        } else {
            result.push_back(-1);
        }
        
        
        //search for upper bound
        first = 0;
        end = n - 1;
        
        while(first + 1 < end) {
            int mid = (first + end) / 2;
            if (A[mid] > target) {
                end = mid;
            } else {
                first = mid;
            }
        }
        
        if (A[end] == target) { // same as [2,2]
            result.push_back(end);
        } else if (A[first] == target) {
            result.push_back(first);
        } else {
            result.push_back(-1);
        }
        
        return result;
    }
    
};



int main(int argc, const char * argv[])
{
  
    
    return 0;
}

