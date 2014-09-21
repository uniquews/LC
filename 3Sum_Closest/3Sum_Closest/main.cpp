//
//  main.cpp
//  3Sum_Closest
//
//  Created by Shuai Wang on 7/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() == 0) {
            return 0;
        }
        
        sort(num.begin(), num.end());
        int gap = INT_MAX;
        int result = 0;
        for (int i = 0; i < num.size() - 2; i++) {
            int start = i + 1;
            int end = num.size() - 1;
            while (start < end) {
                if (num[i] + num[start] + num[end] == target) {
                    return target;
                } else if (num[i] + num[start] + num[end] > target) {
                    if (abs(num[i] + num[start] + num[end] - target) < gap) {
                        result = num[i] + num[start] + num[end];
                        gap = abs(num[i] + num[start] + num[end] - target);
                    }
                    
                    end--;
                } else {
                    if (abs(num[i] + num[start] + num[end] - target) < gap) {
                        result = num[i] + num[start] + num[end];
                        gap = abs(num[i] + num[start] + num[end] - target);
                    }
                    
                    start++;
                }
            }
        }
        
        return result;
    }
};


int main(int argc, const char * argv[])
{

    // insert code here...
//    vector<int> A = {1,1,1,0};
//    int target = 100;
    vector<int> A = {0,1,2};
    int target = 0;
    Solution su;
    cout << su.threeSumClosest(A, target) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}

