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
        if(num.size()< 3) return 0;
        sort(num.begin(), num.end());
        int gap = INT_MAX;
        int result = 0;
        for(auto start = num.begin(); start < prev(num.end(),2); start = upper_bound(next(start), prev(num.end(), 2), *start)){
            auto second = next(start);
            auto third = prev(num.end());
            
            while(second < third){
                int sum = *start + *second + *third;
                if(abs(target - sum) < gap){
                    gap = abs(target - sum);
                    result = sum;
                }
                
                if(sum > target){
                    third = prev(lower_bound(second, third, *third));
                }else
                    second = upper_bound(second, third, *second);
            }
            
            
        }
        return result;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

