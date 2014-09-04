//
//  main.cpp
//  pow
//
//  Created by Shuai Wang on 3/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int sqrt(int x) {
        if (x < 2) {
            return x;
        }
        
        int left = 1;
        int right = x / 2;
        int last_mid;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (x / mid > mid) {
                left = mid + 1;
                last_mid = mid; // 最后取整形数，3 ^ 1/2 = 1，如果得不到精确值，则保留最后一个小的数作为结果，符合整形数
            } else if (x / mid < mid) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        
        return last_mid;
    }
};
int main(int argc, const char * argv[])
{

    // insert code here...
    
    double result= Solution::pow(2,-2);
    std::cout << result<<endl;
    return 0;
}


// 1 1