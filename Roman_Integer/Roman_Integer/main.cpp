//
//  main.cpp
//  Roman_Integer
//
//  Created by Shuai Wang on 7/8/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        if(s.length() == 0) return 0;
        int length = (int)s.length();
        
        map<char, int> mm;
        mm['I'] = 1;
        mm['V'] =5;
        mm['X'] =10;
        mm['L'] = 50;
        mm['C'] =100;
        mm['D'] =500;
        mm['M'] =1000;
        
        int sum = mm[s[length-1]];
        
        for(int i = length-2; i>=0; i--){
            if(mm[s[i]] < mm[s[i+1]]){
                sum -=mm[s[i]];
            }else{
                sum +=mm[s[i]];
            }
        }
        return sum;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

