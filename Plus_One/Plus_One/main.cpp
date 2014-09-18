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
        vector<int> result;
        vector<int> :: iterator it = result.begin();
        for (int i = digits.size() - 1; i >= 0; i--) {
            int temp = carry + digits[i];
            int next = temp / 10;
            result.insert(it, temp % 10);
            carry = next;
            it = result.begin();
        }
        
        if (carry > 0) {
            result.insert(result.begin(), carry);
        }
        
        return result;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

