//
//  main.cpp
//  Wildcard_Matching
//
//  Created by Shuai Wang on 9/17/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int m = (int)strlen(s);
        int n = (int)strlen(p);
        
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
        
        f[0][0] = true;
        for (int i = 1; i <= m; i++) {
            f[i][0] = false;
        }
        
        for (int i = 1; i <= n; i++) {
            if (p[i - 1] == '*') {
                f[0][i] = f[0][i - 1];
            } else {
                f[0][i] = false;
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    f[i][j] = f[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    f[i][j] = f[i - 1][j] | f[i][j - 1];
                    f[i][j] = f[i - 1][j - 1] | f[i][j];
                }
            }
        }
        
        return f[m][n];
    }
};

int main(int argc, const char * argv[])
{

//    char *s = "aa";
//    char *p = "?*?";
    
    char *s = "aab";
    char *p = "c*a*b";
    
    Solution su;
    cout << su.isMatch(s, p) << endl;
    // insert code here...
    
    return 0;
}

