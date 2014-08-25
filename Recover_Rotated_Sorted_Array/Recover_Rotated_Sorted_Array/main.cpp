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
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        
        if (nums.size() == 0) {
            return;
        }
        
        int pivot = INT_MIN;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                pivot = i;
            }
        }
        
        if (pivot == INT_MIN) {
            return;
        } else {
            auto distance = pivot;
            reverse(nums.begin(), next(nums.begin(), distance + 1));

            reverse(next(nums.begin(), distance + 1), nums.end());
            
            reverse(nums.begin(), nums.end());

            
            
            return;
        }
    }
    
    
};

int main(int argc , const char * argv[])
{

    vector<int> arr = {4,1,2,3};
    
    Solution su;
    su.recoverRotatedSortedArray(arr);
    
    vector<int> :: iterator it = arr.begin();
    for (; it != arr.end(); it++) {
        cout << *it << " ";
    }
    
    cout << endl;
    return 0;
}

