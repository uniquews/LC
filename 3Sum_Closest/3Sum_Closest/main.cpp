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
            return target;
        }
        sort(num.begin(), num.end());
        
        int gap = INT_MAX;
        int tempTarget = 0;
        
        for (int i = 0; i < num.size(); i++) {
           
            int left = i + 1;
            int right = (int)num.size() - 1;
            while (left < right) {
                if (num[i] + num[left] + num[right] > target) {
                    if (abs(num[i] + num[left] + num[right] - target) < gap) {
                        gap = abs(num[i] + num[left] + num[right] - target);
                        tempTarget = num[i] + num[left] + num[right];
                    }
                    right--;
                    
                } else if (num[i] + num[left] + num[right] < target){
                    if (abs(num[i] + num[left] + num[right] - target) < gap) {
                        gap = abs(num[i] + num[left] + num[right] - target);
                        tempTarget = num[i] + num[left] + num[right];
                    }
                    left++;
                    
                } else {
                    tempTarget = target;
                    gap = 0;
                    while (left + 1 < right && num[left] == num[left + 1]) {
                        left++;
                    }
                    
                    while (right - 1 > left && num[right - 1] == num[right]) {
                        right--;
                    }
                    
                    left++;
                    right--;
                }
            }
            
            while (i + 1 < num.size() && num[i] == num[i + 1]) {
                i++;
            }
        }
        
        return tempTarget;
    }
    
};


int main(int argc, const char * argv[])
{

    // insert code here...
    vector<int> A = {1,1,1,0};
    int target = 100;
    Solution su;
    cout << su.threeSumClosest(A, target) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}

