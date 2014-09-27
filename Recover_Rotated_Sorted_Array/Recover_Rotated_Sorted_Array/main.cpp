//
//  main.cpp
//  Recover_Rotated_Sorted_Array
//
//  Created by Shuai Wang on 8/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void recoverRotatedSortedArray(int nums[], int n) {
        // write your code here
        if (n == 0) {
            return;
        }
        
        int pivot = n - 1;
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        
        if (pivot == n - 1) {
            return;
        }
        
        int start = 0;
        int end = pivot;
        
        while (start <= end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
        
        start = pivot + 1;
        end = n - 1;
        
        while (start <= end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
        
        start = 0;
        end = n - 1;
        while (start <= end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
        
        return;
     
    }
    
    
};

int main(int argc , const char * argv[])
{

    int nums[] = {1,1,1,1,1};
    
    Solution su;
    su.recoverRotatedSortedArray(nums, 5);
    
    for (int i = 0; i < 5; i++) {
        cout << nums[i] <<endl;
    }
    
    cout << endl;
    return 0;
}

