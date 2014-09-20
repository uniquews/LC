//
//  main.cpp
//  Multiply_String
//
//  Created by Shuai Wang on 8/5/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

//class Solution {
//public:
//    string multiply(string num1, string num2) {
//        if(num1.size() == 0 || num2.size() == 0)
//            return 0;
//        
//        string result (num1.size() + num2.size() + 1, '0');
//        
//        
//        reverse(num1.begin(), num1.end());
//        reverse(num2.begin(), num2.end());
//        
//        for(int i = 0; i < num1.size(); i++){
//            int digit1 = num1[i] - '0';
//            int carry = 0;
//            for(int j = 0; j < num2.size(); j++){
//                int digit2 = num2[j] - '0';
//                int exist = result[i + j] - '0';
//                result[i + j] = (digit1 * digit2 + exist + carry) % 10 + '0';
//                carry = (digit1 * digit2 + exist + carry) / 10;
//            }
//            
//            if(carry > 0){
//                result[i + num2.size()] = carry + '0';
//            }
//        }
//        
//        reverse(result.begin(), result.end());
//        
//        int start = 0;
//        while(result[start] - '0' == 0 && start < result.size()){
//            start++;
//        }
//        
//        if(start == result.size()){
//            return "0";
//        }
//        else{
//            return result.substr(start, result.size() - start);
//        }
//        
//    }
//};

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() == 0  || num2.size() == 0) {
            return "";
        }
        
        string result (num1.size() + num2.size() + 1, '0');
        reverse(num1.begin(), num2.end());
        reverse(num1.begin(), num2.end());
        
        for (int i = 0; i < num1.size(); i++) {
            int digit = num1[i] - '0';
            int carry = 0;
            for (int j = 0; j < num2.size(); j++) {
                int digit2 = num2[j] - '0';
                int exist = result[i + j] - '0';
                result[i + j] = (digit * digit2 + carry + exist) % 10 + '0';
                carry = (digit * digit2 + carry + exist) / 10;
                
            }
            
            if (carry > 0) {
                result[i + num2.size()] = carry + '0';
            }
        }
        
        reverse(result.begin(), result.end());
        
        int start = 0;
        while(result[start] - '0' == 0 && start < result.size()){
            start++;
        }
        
        if(start == result.size()){
            return "0";
        }
        else{
            return result.substr(start, result.size() - start);
        }
        

        
        return result;
    }
};

int main(int argc, const char * argv[])
{

    string num1 = "2";
    string num2 = "3";
    Solution su;
    cout <<  su.multiply(num1, num2) << endl;
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

