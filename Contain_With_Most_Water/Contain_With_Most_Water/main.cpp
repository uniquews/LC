//
//  main.cpp
//  Contain_With_Most_Water
//
//  Created by Shuai Wang on 7/11/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.size() ==  0) {
            return 0;
        }
        
        
        
        int left = 0;
        int right = height.size() - 1;
        
        int result = 0;
        
        
        while (left <= right) {
            int tmp = (right - left) * min(height[left], height[right]);
            result = max(result, tmp);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return result;
    }
};


int main(int argc, const char * argv[])
{

    vector<int> ex = {0,2};
    Solution su;
    cout << su.maxArea(ex);
    return 0;
}

