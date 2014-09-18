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

//class Solution {
//public:
//    vector<int> plusOne(vector<int> &digits) {
//        int carry = 1;
//        
//        for(int i = digits.size()-1; i>=0; i--){
//            int temp = digits[i] + carry;
//            int next = temp/10;
//            digits[i] = temp % 10;
//            carry = next;
//            
//        }
//        
//        if(carry >0) digits.insert(digits.begin(), carry);
//        
//        return digits;
//    }
//};

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

    vector<int> digits = {9};
    Solution su;
    vector<int> result = su.plusOne(digits);

    
//    vector<int> test;
//    vector<int> :: iterator it = test.begin();
//    test.insert(it, 1);
//    it = test.begin();
//    test.insert(it, 2);
//    cout << test[0];
//    cout << test[1];
    return 0;
}

