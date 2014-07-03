//
//  main.cpp
//  Plus_One
//
//  Created by Shuai Wang on 7/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        
        for(int i = digits.size()-1; i>=0; i--){
            int temp = digits[i] + carry;
            int next = temp/10;
            digits[i] = temp % 10;
            carry = next;
            
        }
        
        if(carry >0) digits.insert(digits.begin(), carry);
        
        return digits;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

