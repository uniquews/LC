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
            return -1;
        }
        
        int start = 0;
        int end = (int)num.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (num[mid] < num[mid - 1] && num[mid] < num[mid + 1]) {
                return num[mid];
            } else if ((num[start] < num[mid]) && num[mid] < num[end]) {
                end = mid;
            } else if (num[start] < num[mid]) {
                start = mid;
            } else if (num[mid] < num[end]) {
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

