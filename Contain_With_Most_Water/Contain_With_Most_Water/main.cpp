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
        int end = height.size() - 1;
        int area = min(height[start], height[end]) * (end - start);
        while (start < end) {
            
            if (height[start] < height[end]) {
                start++;
            } else {
                end--;
            }
            
            int tmp = min(height[start], height[end]) * (end - start);
            
            if (area < tmp) {
                area = tmp;
            }
            
        }
        
        return area;
    }
    
};


int main(int argc, const char * argv[])
{

    vector<int> ex = {1,1};
    Solution su;
    cout << su.maxArea(ex);
    return 0;
}

