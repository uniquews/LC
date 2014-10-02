//
//  main.cpp
//  Palindrome_Partitioning2
//
//  Created by Shuai Wang on 6/25/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int minCut(string s) {
//        if (s.size() == 0) {
//            return 0;
//        }
//        
//        vector<vector<bool>> isPP(s.size(), vector<bool> (s.size(), false));
//        for (int i = s.size() - 1; i >= 0; i--) {
//            for (int j = i; j < s.size(); j++) {
//                if (s[i] == s[j] && (j - i <= 2 || isPP[i + 1][j - 1])) {
//                    isPP[i][j] = true;
//                }
//            }
//        }
//        
//        vector<int> f(s.size());
//        for (int i = 0; i < s.size(); i++) {
//            f[i] = i;
//        }
//        
//        if (s[0] == s[1]) {
//            f[1] = 0;
//        }
//        
//        for (int i = 2; i < s.size(); i++) {
//            if (isPP[0][i]) {
//                f[i] = 0;
//            } else {
//                for (int j = 0; j < i; j++) {
//                    if (isPP[j + 1][i]) {
//                        f[i] = min(f[i], f[j] + 1);
//                    }
//                }
//            }
//        }
//        
//        return f[s.size() - 1];
//        
//        
//    }
//    
//};


class Solution {
public:
    int minCut(string s) {
        if (s.size() == 0) {
            return 0;
        }
        
        int n = (int)s.size();
        vector<vector<bool>> isPP(n, vector<bool> (n, false));
        
        for (int i = 0; i < n; i++) {
            isPP[i][i] = true;
        }
        
        for (int i = n - 1; i >=0 ; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || isPP[i + 1][j - 1])) {
                    isPP[i][j] = true;
                }
            }
        }
        
        
        vector<int> f(n, INT_MAX);
        f[0] = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (isPP[0][i]) {
                    f[i] = 0;
                } else if (isPP[j][i]) {
                    f[i] = min(f[i], f[j - 1] + 1);
                }
            }
        }
        return f[n - 1];
    }
};

int main(int argc, const char * argv[])
{

    string s = "cdd";
    Solution su;
    cout << su.minCut(s) << endl;
    return 0;
}

