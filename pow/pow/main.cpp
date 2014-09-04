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
    double pow(double x, int n) {
        if (n > 0) {
            return power(x, n);
        } else if (n == 0){
            return 1;
        } else {
            return 1.0/power(x, -n);
        }
    }
    
    
    double power(double x, int n) {
        
        if (n == 0) {
            return 1;
        }
        
        double tmp = power(x, n/2) ;
        if (n % 2 == 0) {
            return tmp * tmp;
        } else {
            return tmp * tmp * x;
        }
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