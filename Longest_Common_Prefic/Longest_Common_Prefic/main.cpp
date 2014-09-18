//
//  main.cpp
//  Longest_Common_Prefic
//
//  Created by Shuai Wang on 9/17/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        }
        int lcp = strs[0].size();
        
        string tmp = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            for (int j = 0; j < lcp; j++) {
                if (tmp[j] != strs[i][j]) {
                    lcp = j;
                    break;
                }
            }
        }
        
        return tmp.substr(0, lcp);
    }
};
int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

