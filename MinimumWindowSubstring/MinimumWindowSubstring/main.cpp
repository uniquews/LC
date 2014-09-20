//
//  main.cpp
//  MinimumWindowSubstring
//
//  Created by Shuai Wang on 5/30/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string minWindow(string S, string T) {
        if (S.size() == 0) {
            return "";
        }
        
        if (T.size() == 0) {
            return "";
        }
        
        if (S.size() < T.size()) {
            return "";
        }
        
        int w_start = 0;
        int w_end = 0;
        int min_wnd = INT_MAX;
        int min_start = 0;
        int numOfSatisfied = 0;
        int numOfNeeded = 0;
        
        vector<int> needed(256, 0);
        vector<int> existed(256, 0);
        
        for (int i = 0; i < T.size(); i++) {
            needed[T[i]]++;
            numOfNeeded++;
        }
        
        for (; w_end < S.size(); w_end++) {
            if (needed[S[w_end]] != 0) {
                if (existed[S[w_end]] < needed[S[w_end]]) {
                    numOfSatisfied++;
                }
                existed[S[w_end]]++;
                
            }
            
            if (numOfSatisfied == numOfNeeded) {
                while (existed[S[w_start]] > needed[S[w_start]] || needed[S[w_start]] == 0) {
                    existed[S[w_start]]--;
                    w_start++;
                }
                
                if (min_wnd > w_end - w_start + 1) {
                    min_wnd = min (min_wnd, w_end - w_start + 1);
                    min_start = w_start;
                }
            }
           
        }
        
        if (min_wnd == INT_MAX) {
            return "";
        } else {
            return S.substr(min_start, min_wnd);
        }
        
        
    }
};

int main(int argc, const char * argv[])
{

    string S = "a";
    string T = "a";
    Solution su;
    cout << su.minWindow(S, T) << endl;
    return 0;
}

