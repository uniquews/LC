//
//  main.cpp
//  Count And Say
//
//  Created by Shuai Wang on 9/17/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string begin = "1";
        
        if (n == 0) {
            return "";
        }
        
        if (n == 1) {
            return begin;
        }
        
        while (n > 1) {
            string newStr = "";
            int i = 0;
            while (i < begin.size()) {
                char tmp = begin[i];
                int j = i;
                int start = i;
                while (j < begin.size() && begin[j] == tmp) {
                    j++;
                }
                
                newStr.append(to_string(j - start));
                newStr += tmp;
                i = j;
            
            }
            begin = newStr;
            n--;
            
        }
        
      return begin;
    }
};

int main(int argc, const char * argv[])
{

    int n = 4;
    Solution su;
    cout << su.countAndSay(n) << endl;
    return 0;
}

