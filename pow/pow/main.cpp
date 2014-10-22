//
//  main.cpp
//  pow
//
//  Created by Shuai Wang on 3/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
using namespace std;
//class Solution {
//public:
//    double pow(double x, int n) {
//        if (n > 0) {
//            return power(x, n);
//        } else if (n == 0){
//            return 1;
//        } else {
//            return 1.0/power(x, -n);
//        }
//    }
//    
//    
//    double power(double x, int n) {
//        
//        if (n == 0) {
//            return 1;
//        }
//        
//        double tmp = power(x, n/2) ;
//        if (n % 2 == 0) {
//            return tmp * tmp;
//        } else {
//            return tmp * tmp * x;
//        }
//    }
//    
//};

class Solution {
public:
    double pow(double x, int n) {
        
        if (n == 0) {
            return 1;
        }
        
        if (n > 0) {
            double tmp = pow(x, n / 2);
            if (n % 2 == 0.0) {
                return tmp * tmp;
            } else {
                return tmp * tmp * x;
            }
            
        } else {
            double tmp = pow(x, (-n) / 2);
            if (n % 2 == 0.0) {
                return 1 / (tmp * tmp);
            } else {
                return 1 / (tmp * tmp * x);
            }
            
        }
        
    }
};
int main(int argc, const char * argv[])
{

    // insert code here...
    
    Solution su;
    double result= su.pow(0.77964,-4);
    std::cout << result<<endl;
    return 0;
}


// 1 1