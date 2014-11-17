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

class Solution {
public:
    int minCut(string s) {
        if (s.size() == 0 || s.size() == 1) {
            return 0;
        }
        
        vector<vector<bool>> isPP(s.size(), vector<bool>(s.size(), false));
        vector<int> f(s.size() + 1, INT_MAX);
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && (j - i <= 2 || isPP[i + 1][j - 1])) {
                    isPP[i][j] = true;
                }
            }
        }
        
        f[0] = -1;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (isPP[j][i - 1]) {
                    f[i] = min(f[j] + 1, f[i]);
                }
            }
        }
        
        return f[s.size()];
    }
};

int main(int argc, const char * argv[])
{

    string s = "ccc";
    Solution su;
    cout << su.minCut(s) << endl;
    return 0;
}

