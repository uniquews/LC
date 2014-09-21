//
//  main.cpp
//  Reverse String
//
//  Created by Shuai Wang on 9/20/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        if (s.size() == 0) {
            return;
        }
        int i  = (int)s.size() - 1;
        string rs = "";
        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') {
                i--;
            }
            
            if (i < 0) {
                
                rs.resize(rs.size() - 1);
                s = rs;
                return;
            }
            
            int tail = i;
            while (i >= 0 && s[i] != ' ') {
                i--;
            }
            
            
            string tmp = s.substr(i + 1, tail - i);
            
            rs.append(tmp.append(" "));
            
        }
        
        rs.resize(rs.size() - 1);
        s = rs;
        return;
    }
    
};

int main(int argc, const char * argv[])
{

   
    string s = " 1";
    Solution su;
    su.reverseWords(s);
    cout << s << endl;
    return 0;
}

