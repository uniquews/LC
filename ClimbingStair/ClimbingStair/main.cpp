//
//  main.cpp
//  ClimbingStair
//
//  Created by Shuai Wang on 3/28/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) {
            return 0;
        }
        
        if (n == 1) {
            return 1;
        }
        
        vector<int> f(n + 1);
        f[1] = 1;
        f[2] = 2;
        for (int i = 3; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        
        return f[n];
    }
};


int main(int argc, const char * argv[])
{

    // insert code here...
    //int result1 = Solution::climbstair(100);
    int result2 = Solution::climbStair(3);
    //std::cout << result1<<endl;
    std::cout << result2<<endl;

    return 0;
}

