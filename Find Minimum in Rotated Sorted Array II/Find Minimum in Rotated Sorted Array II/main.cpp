//
//  main.cpp
//  Find Minimum in Rotated Sorted Array II
//
//  Created by Shuai Wang on 10/21/14.
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
            } else if (num[start] > num[mid]) {
                end = mid;
            } else {
                start++;
            }
            
        }
        
        if (num[start] <= num[end]) {
            return num[start];
        } else {
            return num[end];
        }
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

