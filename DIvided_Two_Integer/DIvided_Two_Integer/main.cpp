//
//  main.cpp
//  DIvided_Two_Integer
//
//  Created by Shuai Wang on 8/6/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

//class Solution {
//public:
//    int divide(int dividend, int divisor) {
////        if(divisor == 0) return 0; // ???
//        bool sign = true;
//        int result = 0;
//        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)){
//            sign = false;
//        }
//        
//        unsigned int divd = abs(dividend);
//        unsigned int divi = abs(divisor);
//        
//        unsigned int c = 1;
//        
//        while(divd > divi){
//            c = c << 1;
//            divi = divi << 1;
//        }
//        
//        while(divd >= (unsigned int)abs(divisor)){
//            while(divd >= divi){
//                divd -= divi;
//                result += c;
//            }
//            
//            divi = divi >> 1;
//            c = c >> 1;
//            
//        }
//        
//        
//        if(sign == false){
//            return (-1) * result;
//        }else{
//            return result;
//        }
//    }
//};

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = true;
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)){
            sign = false;
        }
        long a = abs(long(dividend));
        long b = abs(long(divisor));
        int ans = 0;
        
        while (a >= b) {
            int shift = 0;
            while ((b << shift) <= a) {
                shift++;
            }
            ans += 1 << (shift-1);
            a = a - (b << (shift-1));
        }
        
        return sign ? ans : -ans;
    }


};

int main(int argc, const char * argv[])
{

    int a = 10;
    int b = 2;
    
    Solution su;
    cout << su.divide(a, b) << endl;
    
    return 0;
}

