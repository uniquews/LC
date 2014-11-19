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
        string startStr = "1";
        while (n > 1) {
            string tmp = "";
            int start = 0;
            while (start < startStr.size()) {
                int end = start;
                while (end < startStr.size() && startStr[end] == startStr[start]) {
                    end++;
                }
                int len = end - start;
                tmp.append(to_string(len)).append(string next(1, startStr[start]));
                start = end;
                
            }
            startStr = tmp;
            n--;
        }
        return startStr;
    }
};

int main(int argc, const char * argv[])
{

    int n = 4;
    Solution su;
    cout << su.countAndSay(n) << endl;
    return 0;
}

