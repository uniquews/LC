//
//  main.cpp
//  Find Minimun in Sorted Array
//
//  Created by Shuai Wang on 10/15/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        if (num.size() == 0) {
            return 0;
        }
        
        int start = 0;
        int end = num.size() - 1;
        
        while (start + 1 < end) {
            if (num[start] < num[end]) {
                return num[start];
            }
            
            int mid = start + (end - start) / 2;
            if (num[start] < num[mid]) {
                start = mid;
            } else {
                end = mid;
            }
            
        }
        
        if (num[start] < num[end]) {
            return num[start];
        } else {
            return num[end];
        }
        
        
        
    }
    
};

int main(int argc, const char * argv[])
{

    Solution su;
    vector<int> num = {1,2,3,4};
    cout << su.findMin(num) << endl;
    return 0;
}

