//
//  main.cpp
//  Sqrt(x)
//
//  Created by Shuai Wang on 7/30/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int sqrt(int x) {
        int left = 1;
        int right = x/2;
        int mid;
        int last_mid = 0;
        
        if(x<2) return x; // in while, 1 and 0 will both return 0. However, 1 should return 1
        
        while(left <= right){
            int mid = (right+ left)/2;
            if(x/mid > mid){
                left = mid+1;
                last_mid = mid;  // must add this, when input is {2}
            }else if(x/mid < mid){
                right = mid-1;
                // last_mid = mid;  cannot add this, when input is {6}
            }else{
                return mid;
            }
        }
        
        return last_mid;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

