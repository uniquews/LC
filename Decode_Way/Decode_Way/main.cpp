//
//  main.cpp
//  Decode_Way
//
//  Created by Shuai Wang on 6/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int numDecodings(string s) {
//        if (s.size() == 0) {
//            return 0;
//        }
//        
//        int n = (int)s.size();
//        vector<int> f(n + 1);
//        f[0] = 1;
//        for (int i = 1; i <= n; i++) {
//            if (i == 1) {
//                if (s[0] == '0') {
//                    f[1] = 0;
//                } else {
//                    f[1] = 1;
//                }
//            } else {
//                if (s[i - 1] == '0') {
//                    f[i] = 0;
//                } else {
//                    f[i] = f[i - 1];
//                }
//                
//                if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] >= '0' && s[i - 1] <= '6')) {
//                    f[i] += f[i - 2];
//                }
//            }
//        }
//        
//        return f[n];
//    }
//};


class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) {
            return 0;
        }
        
        vector<int> f(s.size() + 1, 0);
        f[0] = 1;
        if (s[0] == '0') {
            f[1] = 0;
        } else {
            f[1] = 1;
        }
        
        for (int i = 2; i <= s.size(); i++) {
            if (s[i - 1] != 0) {
                f[i] = f[i - 1];
            }
            
            if (s[i - 2] >= '1' && s[i - 2] <= '2' && s[i - 1] >= '0' && s[i - 1] <= '6') {
                f[i] += f[i - 2];
            }
        }
        
        return f[s.size()];
        
    }
    
};
int main(int argc, const char * argv[])
{
    string ss = "10";
    Solution su;
    cout << su.numDecodings(ss) << endl;
}

