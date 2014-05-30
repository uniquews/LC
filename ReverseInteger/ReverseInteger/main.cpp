//
//  main.cpp
//  ReverseInteger
//
//  Created by Shuai Wang on 5/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
using namespace std;


class Solution{

public:
    int reverse(int x){
        int lastDigit = 0;
        int result = 0;
        bool isNeg = x>0?false:true;//check the postive and negetive
        
        x =abs(x);//Don't foget
        
        while(x>0){ //reverse procedure
            lastDigit = x%10;
            result = result*10+lastDigit;
            x = x/10;
        }
        
        if(result<0) return -1;
        if(isNeg==true)
            result = result*-1;
        
        
        return result;
    }
    

};

int main(int argc, const char * argv[])
{

    // insert code here...
    Solution *s = new Solution();
    int a =2147471119;
    cout<< s->reverse(a)<<endl;
    return 0;
}

