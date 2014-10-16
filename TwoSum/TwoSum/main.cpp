//
//  main.cpp
//  TwoSum
//
//  Created by Shuai Wang on 5/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        sort(nums.begin(), nums.end());
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            int tmp = target - nums[i];
            int found  = binarySearch(nums, tmp);
            if (found == -1) {
                continue;
            } else {
                result.push_back(i + 1);
                result.push_back(found + 1);
                break;
            }
            
        }
        
        return result;
    }
    
    int binarySearch(vector<int> &nums, int target) {
        int start = 0;
        int end = (int)nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if (nums[start] == target) {
            return start;
        }
        
        if (nums[end] == target) {
            return end;
        }
        
        return -1;
    }
};




int main(int argc, const char * argv[])
{

    // insert code here...

    Solution *s = new Solution();
    vector<int> num = {1,0,-1};
    vector<int> &numbers = num;
    vector<int> result;
    result = s->twoSum(numbers, -1);
    
    
    vector<int>::iterator iter;
    for(iter = result.begin(); iter!=result.end();iter++){
        cout << *iter<<" ";
    }
    
    cout << endl;
    return 0;
}

