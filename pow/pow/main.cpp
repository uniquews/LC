//
//  main.cpp
//  pow
//
//  Created by Shuai Wang on 3/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution{
public:
    
    static double pow(double x,int n){
        
        if(n>0){
            return power(x,n);
        }else{
            return power(x,-n);
        }
    }
    
    
    static double power(double x, int n){
        if(n==0)
            return 1;
        if(n%2==0)
            return power(x, n/2)*power(x, n/2);
        else
            return power(x,n/2)*power(x,n/2)*x;
    }
};


int main(int argc, const char * argv[])
{

    // insert code here...
    
    double result= Solution::pow(.2,4);
    std::cout << result<<endl;
    return 0;
}


// 1 1