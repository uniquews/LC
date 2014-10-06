//
//  main.cpp
//  Majority_Number1
//
//  Created by Shuai Wang on 8/31/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        if (nums.size() == 0) {
            return 0;
        }
        
        int maj = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != maj) {
                count--;
            } else {
                count++;
            }
            
            if (count == 0) {
                maj = nums[i];
                count++;
            }
        }
        
        return maj;
    }
};
int main(int argc, const char * argv[])
{

        return 0;
}

