//
//  main.cpp
//  ClimbingStair
//
//  Created by Shuai Wang on 3/28/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution{
public:
    //Too trivial to use recursion
    static int climbstair(int n){
        if(n==1) return 1;
        if(n==2) return 2;
        return climbstair(n-1)+climbstair(n-2);
    }

    
    static int climbStair(int n){
        if(n==1) return 1;
        if(n==2) return 2;
        int last=0;
        int lastlast =0;
        int result=0;
        for(int i=1; i<=n; i++){
            if(i==1){
                last=1;
                result = last+lastlast;
                lastlast=last;
                last=result;
            }else{
                result = last+lastlast;
                lastlast=last;
                last=result;
            
            }
        
        }
        return result;
    
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

