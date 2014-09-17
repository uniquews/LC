//
//  main.cpp
//  Add_Binary
//
//  Created by Shuai Wang on 9/17/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        int digit = 0;
        int maxLength = a.size() > b.size() ? a.size() : b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        for (int i = 0; i < maxLength; i++) {
            int da = i > a.size() - 1 ? 0 : a[i] - '0';
            int db = i > b.size() - 1 ? 0 : b[i] - '0';
            
            digit = (da + db + carry) % 2;
            carry = (da + db + carry) / 2;
            result.insert(result.begin(), digit + '0');
        }
        
        if (carry == 1) {
            result.insert(result.begin(), carry + '0');
        }
        
        return result;
    }
};
int main(int argc, const char * argv[])
{

    string a = "1";
    string  b = "1";
    Solution su;
    cout << su.addBinary(a, b) << endl;
    
    return 0;
}

