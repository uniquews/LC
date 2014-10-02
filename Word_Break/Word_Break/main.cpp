//
//  main.cpp
//  Word_Break
//
//  Created by Shuai Wang on 9/15/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;


//class Solution {
//public:
//    bool wordBreak(string s, unordered_set<string> &dict) {
//        vector<bool> f(s.length() + 1, false);
//        f[0] = true;  // !!!!!!!!!!!!!!!
//        for (int i = 1; i <= s.length(); i++) {
//            for (int j = i - 1; j >= 0; j--) {
//                if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
//                    f[i] = true;
//                    break;
//                }
//            }
//        }
//        
//        return f[s.length()];
//        
//    }
//    
//    
//};

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.size() == 0) {
            return false;
        }
        
        int n = (int)s.size();
        
        vector<bool> f(n + 1, false);
        f[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                string tmp = s.substr(j, i - j);
                
                if (dict.find(tmp) != dict.end()) {
                    f[i] = f[i] || f[j];
                }
            }
        }
        
        return f[n];
        
    }
};

int main(int argc, const char * argv[])
{

    string s = "a";
    unordered_set<string> hash_set = {"a"};
    Solution su;
    cout << su.wordBreak(s, hash_set) <<endl;
    return 0;
}

