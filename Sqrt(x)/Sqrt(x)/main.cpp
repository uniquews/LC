//
//  main.cpp
//  Sqrt(x)
//
//  Created by Shuai Wang on 7/30/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

//class Solution {
//public:
//    int sqrt(int x) {
//        if (x < 2) {
//            return x;
//        }
//        
//        int left = 1;
//        int right = x / 2;
//        int last_mid = 1;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (mid == x / mid) {
//                return mid;
//            } else if (mid < x / mid) {
//                left = mid + 1;
//                last_mid = mid;
//            } else {
//                right = mid - 1;
//            }
//        }
//        
//        return last_mid;
//    }
//    
//};

class Solution {
public:
    int sqrt(int x) {
        if (x < 2) {
            return x;
        }
        
        int start = 0;
        int end = x / 2;
        int last_mid = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid == x / mid) {
                return mid;
            } else if (mid < x / mid) {
                last_mid = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return last_mid;
    }
};

int main(int argc, const char * argv[])
{

    Solution su;
    su.sqrt(2);
    return 0;
}

