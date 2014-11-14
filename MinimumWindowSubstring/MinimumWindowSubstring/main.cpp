//
//  main.cpp
//  MinimumWindowSubstring
//
//  Created by Shuai Wang on 5/30/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    string minWindow(string S, string T) {
        if (S.size() == 0 || T.size() == 0) {
            return "";
        }
        
        if (T.size() > S.size()) {
            return "";
        }
        
        unordered_map<char, int> exist;
        unordered_map<char, int> needed;
        int num = 0;
        for (int i = 0; i < T.size(); i++) {
            needed[T[i]]++;
        }
        
        int start = 0;
        int end = 0;
        int w_start = 0;
        int wnd = INT_MAX;
        
        while (end < S.size()) {
            while (end < S.size() && num < T.size()) {
                if (needed[S[end]] > exist[S[end]]) {
                    num++;
                }
                exist[S[end]]++;
                end++;
            }
            if (num == T.size()) {
                while (needed[S[start]] == 0 || exist[S[start]] > needed[S[start]]) {
                    exist[S[start]]--;
                    start++;
                }
                
                if (wnd > end - start) {
                    wnd = end - start;
                    w_start = start;
                }

                exist[S[start]]--;
                start++;
                num--;
            }

        }
        
        if (wnd == INT_MAX) {
            return "";
        }
        
        return S.substr(w_start, wnd);
    }
};
int main(int argc, const char * argv[])
{

//    string S = "cabwefgewcwaefgcf";
//    string T = "cae";
    string S = "ADOBECODEBANC";
    string T = "ABC";
    
    Solution su;
    cout << su.minWindow(S, T) << endl;
    return 0;
}

