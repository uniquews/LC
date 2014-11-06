//
//  main.cpp
//  4Sum
//
//  Created by Shuai Wang on 7/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &num, int target) {
        if (num.size() == 0) {
            return vector<vector<int>> ();
        }
        
        sort(num.begin(), num.end());
        
        vector<vector<int>> result;
        
        for (int i = 0; i < num.size(); i++) {
            vector<int> eachResult;
            eachResult.push_back(num[i]);
            for (int j = i + 1; j < num.size(); j++) {
                eachResult.push_back(num[j]);
                int tmp = target - num[i] - num[j];
                twoSum(num, result, eachResult, tmp, j);
                eachResult.pop_back();
                
                
                while (j + 1 < num.size() && num[j] == num[j + 1]) {
                    j++;
                }
            }
            eachResult.pop_back();
            
            while (i + 1 < num.size() && num[i] == num[i + 1]) {
                i++;
            }
        }
        
        return result;
    }
    
    void twoSum(vector<int> num, vector<vector<int>> &result, vector<int> &eachResult, int target, int currentIndex) {
        int left = currentIndex + 1;
        int right = num.size() - 1;
        while (left < right) {
            if (num[left] + num[right] > target) {
                right--;
            } else if (num[left] + num[right] < target) {
                left++;
            } else {
                eachResult.push_back(num[left]);
                eachResult.push_back(num[right]);
                result.push_back(eachResult);
                while (left + 1 < right && num[left] == num[left + 1]) {
                    left++;
                }
                
                while (right - 1 >  left && num[right] == num[right - 1]) {
                    right--;
                }
                
                left++;
                right--;
                eachResult.pop_back();
                eachResult.pop_back();
            }
            
        }
        
        return;
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

