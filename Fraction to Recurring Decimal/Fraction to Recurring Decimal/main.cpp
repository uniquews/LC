//
//  main.cpp
//  Fraction to Recurring Decimal
//
//  Created by Shuai Wang on 12/17/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int64_t n, int64_t d) {
        if (n == 0) {
            return "0";
        }
        
        string res = "";
        
        if (n < 0 ^ d < 0) {
            res += '-';
        }
        
        int64_t numerator = n;
        int64_t denominator = d;
        
        numerator = abs(numerator);  // INT_MIN取绝对值时又溢出，所以用Long
        denominator = abs(denominator);
        
        res += to_string(numerator / denominator);
        
        if (numerator % denominator == 0) {
            return res;
        }
        
        res += '.';
        
        unordered_map<int64_t, int64_t> hashMap;
        
        for (int64_t r = numerator % denominator; r > 0; r = r % denominator) {
            if (hashMap.count(r) > 0) {
                res.insert(hashMap[r], 1, '(');
                res += ')';
                break;
            }
            
            hashMap[r] = res.size();
            r *= 10;
            res += to_string(r / denominator);
        }
        return res;
    }
};

//string fractionToDecimal(long n, long d) {
//    if (n == 0) {
//        return "0";
//    }
//    
//    string res = "";
//    
//    if (n < 0 ^ d < 0) {
//        res += '-';
//    }
//    
//    long numerator = n;
//    long denominator = d;
//    
//    numerator = abs(numerator);  // INT_MIN取绝对值时又溢出，所以用Long
//    denominator = abs(denominator);
//    
//    res += to_string(numerator / denominator);
//    
//    if (numerator % denominator == 0) {
//        return res;
//    }
//    
//    res += '.';
//    
//    unordered_map<long, long> hashMap;
//    
//    for (long r = numerator % denominator; r > 0; r = r % denominator) {
//        if (hashMap.count(r) > 0) {
//            res.insert(hashMap[r], 1, '(');
//            res += ')';
//            break;
//        }
//        
//        hashMap[r] = res.size();
//        r *= 10;
//        res += to_string(r / denominator);
//    }
//    return res;
//}

int main(int argc, const char * argv[]) {
    int a = -1;
    int b = -2147483648;
    cout << fractionToDecimal(a,b) << endl;
    return 0;
}
