//
//  main.cpp
//  ReverseInteger
//
//  Created by Shuai Wang on 5/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
using namespace std;


class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if (x < 0) {
            neg = true;
            x = x * (-1);
        }
        
        int result = 0;
        while (x > 0) {
            int tmp = x % 10;
            result = result * 10 + tmp;
            x = x / 10;
        }
        
        if (result < 0) {
            return 0;
        }
        if (neg == false) {
            return result;
        } else {
            return (-1) * result;
        }
        return result;
    }
};


int main(int argc, const char * argv[])
{

    // insert code here...
    Solution *s = new Solution();
//    int a =2147471119;
    int a =INT_MIN;
    cout<< s->reverse(a)<<endl;
    return 0;
}

