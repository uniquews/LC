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


//class Solution {
//public:
//    string minWindow(string S, string T) {
//        if (S.size() == 0) {
//            return "";
//        }
//        
//        if (T.size() == 0) {
//            return "";
//        }
//        
//        if (S.size() < T.size()) {
//            return "";
//        }
//        
//        int w_start = 0;
//        int w_end = 0;
//        int min_wnd = INT_MAX;
//        int min_start = 0;
//        int numOfSatisfied = 0;
//        int numOfNeeded = 0;
//        
//        vector<int> needed(256, 0);
//        vector<int> existed(256, 0);
//        
//        for (int i = 0; i < T.size(); i++) {
//            needed[T[i]]++;
//            numOfNeeded++;
//        }
//        
//        for (; w_end < S.size(); w_end++) {
//            if (needed[S[w_end]] != 0) {
//                if (existed[S[w_end]] < needed[S[w_end]]) {
//                    numOfSatisfied++;
//                }
//                existed[S[w_end]]++;
//                
//            }
//            
//            if (numOfSatisfied == numOfNeeded) {
//                while (existed[S[w_start]] > needed[S[w_start]] || needed[S[w_start]] == 0) {
//                    existed[S[w_start]]--;
//                    w_start++;
//                }
//                
//                if (min_wnd > w_end - w_start + 1) {
//                    min_wnd = min (min_wnd, w_end - w_start + 1);
//                    min_start = w_start;
//                }
//            }
//           
//        }
//        
//        if (min_wnd == INT_MAX) {
//            return "";
//        } else {
//            return S.substr(min_start, min_wnd);
//        }
//        
//        
//    }
//};

class Solution {
public:
    string minWindow(string S, string T) {
        if (S.size() == 0 || T.size() == 0) {
            return "";
        }
        
        if (S.size() < T.size()) {
            return "";
        }
        
        int w_start = 0;
        int w_end = 0;
        int minw_start = 0;
        int minw = INT_MAX;
        int numOfNeed = 0;
        int numOfSatisfied = 0;
        
        vector<int> exist(256, 0);
        vector<int> need(256, 0);
        
        for (int i = 0; i < T.size(); i++) {
            need[T[i]]++;
            numOfNeed++;
        }
        
        for (; w_end < S.size(); w_end++) {
            if (need[S[w_end]] != 0) {
                if (need[S[w_end]] > exist[S[w_end]]) {
                    numOfSatisfied++;
                }
                exist[S[w_end]]++;
            }
            
            if (numOfNeed == numOfSatisfied) {
                while (need[S[w_start]] == 0 || need[S[w_start]] < exist[S[w_start]]) {
                    
                    if (need[S[w_start]] != 0) {
                        exist[S[w_start]]--;
                    }
                    w_start++;
                }
                
                
                if (minw > w_end - w_start + 1) {
                    minw = w_end - w_start + 1;
                    minw_start = w_start;
                }
                
            }
            
            
        }
        
        if (minw == INT_MAX) {
            return "";
        } else {
            return S.substr(minw_start, minw);
        }
        
        
    }
};

int main(int argc, const char * argv[])
{

    string S = "cabwefgewcwaefgcf";
    string T = "cae";
    Solution su;
    cout << su.minWindow(S, T) << endl;
    return 0;
}

