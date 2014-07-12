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
        int start = 0;
        int end = height.size()-1;
        int result = INT_MIN;
        while(start <end){
            int area = min(height[start], height[end]) * (end - start);
            result = max(area, result);
            if(height[start] <= height[end]){
                start++;
            }else{
                end--;
            }
        }
        
        return result;
    }
};


int main(int argc, const char * argv[])
{

    vector<int> ex = {1,1};
    Solution su;
    cout << su.maxArea(ex);
    return 0;
}

